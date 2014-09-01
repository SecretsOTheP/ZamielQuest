// To do:
// - spaces in search term don't work

#include <stdio.h>
#include "eq_data.h"
#include "mem.c"

void error(char *msg) {
        printf("error: %s\n",msg);
        exit(1);
}

char* clean_name(char *first) {
	int i;
	char* ret_val;
	char* ptr;
	ret_val = malloc(64);

	strcpy(ret_val, first);
	if (*ret_val == '#')
		ret_val++;
	for ( ptr=ret_val ; *ptr ; ptr++ ) {
		if (*ptr == '_')
			*ptr = ' ';
	}
	if (ptr[-1] >= '0' && ptr[-1] <= '9' && ptr[-2] >= '0' && ptr[-2] <= '9') {
		ptr -= 2;
		*ptr = '\0';
	}
	if (ptr-ret_val > 6 && strcmp(ptr-4," pet")==0 && ptr[-5] >= '0' && ptr[-5] <= '9' && ptr[-6] >= '0' && ptr[-6] <= '9') {
		ptr[-6] = '\'';
		ptr[-5] = 's';
	}
	return ret_val;
}

int main(int argc, char **argv) {
	int pid;
	mach_port_t task;
	kern_return_t err;
	PSPAWNINFO pSpawn;
	DWORD address;
	DWORD address_of_target;
	DWORD address_of_guilds;
	char guildList[50][96];
	char line[256];
	int i;
	int d;
	int SortType = 0;
	int SortFullName = 0;
	int SortAddress = 0;
	int SortLoc = 0;
	int SortID = 0;
	int SortIDSpecific = 0;
	int SortTarget = 0;
	int SortLevel = 0;
	int SortMaxLevel = 0;
	char* SortString = NULL;
	char* errString;
	int totalFound = 0;
	int currentZone;

	if (argc < 2) {
		printf("usage: %s <pid>\n", argv[0]);
		return 1;
	}

	pid = atoi(argv[1]);

	// Get arguments
	for (i = 2; i < argc; i++) {
		if (strcasecmp(argv[i], "pc") == 0)
			SortType = 1;
		else if (strcasecmp(argv[i], "pet") == 0)
			SortType = 2;
		else if (strcasecmp(argv[i], "npc") == 0)
			SortType = 3;
		else if (strcasecmp(argv[i], "corpse") == 0)
			SortType = 4;
		else if (strcasecmp(argv[i], "full") == 0)
			SortFullName = 1;
		else if (strcasecmp(argv[i], "address") == 0)
			SortAddress = 1;
		else if (strcasecmp(argv[i], "loc") == 0)
			SortLoc = 1;
		else if (strcasecmp(argv[i], "id") == 0)
			SortID = 1;
		else if (strcasecmp(argv[i], "ids") == 0)
			SortIDSpecific = 1;
		else if (strcasecmp(argv[i], "target") == 0)
			SortTarget = 1;
		else {
			d = strtol(argv[i], &errString, 10);
			if (errString[0] == '\0') {
				if (SortIDSpecific) {
					SortIDSpecific = d;
				} else if (SortLevel) {
					SortMaxLevel = d;
				} else {
					SortLevel = d;
				}
			} else {
				SortString = argv[i];
			}
		}
	}

	// Make sure we're root
	if (getuid() && geteuid())
		error("requires root");

	// Get the task port
	err = task_for_pid(mach_task_self(), pid, &task);
	if ((err != KERN_SUCCESS) || !MACH_PORT_VALID(task))
		error("getting eq task");

	// Get guild list
	memcpy(guildList, mem_read(task, _guilds + 4, 96*50), 96*50);

	// Header
	if (SortTarget) {
		address_of_target = *mem_read(task, _TargetPlayer, 4);
		pSpawn = (PSPAWNINFO)mem_read(task, address_of_target, sizeof(SPAWNINFO));
		if (pSpawn->Type == 0) {
			printf("PC's on EverQuest:\n");
		} else if (pSpawn->Type == 1 && pSpawn->MasterID) {
			printf("Pets on EverQuest:\n");
		} else if (pSpawn->Type == 1) {
			printf("NPC's on EverQuest:\n");
		} else if (pSpawn->Type == 2) {
			printf("Corpses on EverQuest:\n");
		}
	} else {
		if (SortType == 0) {
			printf("Things on EverQuest:\n");
		} else if (SortType == 1) {
			printf("PC's on EverQuest:\n");
		} else if (SortType == 2) {
			printf("Pets on EverQuest:\n");
		} else if (SortType == 3) {
			printf("NPC's on EverQuest:\n");
		} else if (SortType == 4) {
			printf("Corpses on EverQuest:\n");
		}
	}
	printf("---------------------------\n");

	// Get current zone
	address = *mem_read(task, _LocalPlayer, 4);
	pSpawn = (PSPAWNINFO)mem_read(task, address, sizeof(SPAWNINFO));
	currentZone = pSpawn->Zone;

	// Go through every spawn structure
	for ( ; address; address = (vm_address_t)pSpawn->pPrev) {
		pSpawn = (PSPAWNINFO)mem_read(task, address, sizeof(SPAWNINFO));

		// Apply filters
		if (SortType == 1 && pSpawn->Type != 0) // pc
			continue;
		else if (SortType == 2 && (pSpawn->Type != 1 || !pSpawn->MasterID)) // pet
			continue;
		else if (SortType == 3 && pSpawn->Type != 1) // npc
			continue;
		else if (SortType == 4 && pSpawn->Type != 2) // corpse
			continue;
		else if (SortIDSpecific && SortIDSpecific != pSpawn->SpawnID) // id
			continue;
		else if (SortLevel && !SortMaxLevel && SortLevel != pSpawn->Level) // level
			continue;
		else if (SortLevel && SortMaxLevel && (SortLevel > pSpawn->Level || SortMaxLevel < pSpawn->Level)) // min/max level
			continue;
		else if (SortString && !strcasestr(pSpawn->Name, SortString)) // name
			continue;
		else if (SortTarget && address != address_of_target) // target
			continue;
		
		// Start a new line for the corresponding spawn structure
		*line = '\0';

		// Address
		if (SortAddress)
			sprintf(line, "0x%.8x ", address);

		// AFK
		if (pSpawn->AFK && pSpawn->Type != 2)
			sprintf(line, "%sAFK ", line);	

		// Anonymous and roleplay
		if (pSpawn->Anon == 1)
			sprintf(line, "%s[ANONYMOUS] ", line);
		else if (pSpawn->Anon == 2)
			sprintf(line, "%s[ROLEPLAY] ", line);

		// Level and race
		if (pSpawn->Class < sizeof(szClass) / 8)
			sprintf(line, "%s[%d %s]", line, pSpawn->Level, szClass[pSpawn->Class]);
		else
			sprintf(line, "%s[%d Class %d]", line, pSpawn->Level, pSpawn->Class);

		// Name
		if (SortFullName)
			sprintf(line, "%s %s", line, pSpawn->Name);
		else
			sprintf(line, "%s %s", line, clean_name(pSpawn->Name));

		// Race
		if (pSpawn->Race < sizeof(szRace) / 8)
			sprintf(line, "%s (%s)", line, szRace[pSpawn->Race]);
		else
			sprintf(line, "%s (Unknown Race %d)", line, pSpawn->Race);

		if (SortLoc) {
			sprintf(line, "%s (%.2f, %.2f, %.2f)", line, pSpawn->X, pSpawn->Y, pSpawn->Z);
		}

		// Guild
		if (pSpawn->GuildID != -1)
			sprintf(line, "%s <%s>", line, guildList[pSpawn->GuildID]);

		// Type
		if (!SortType) {
			if (pSpawn->Type == 0)
				sprintf(line, "%s [PC]", line);
			else if (pSpawn->Type == 1 && pSpawn->MasterID)
				sprintf(line, "%s [pet]", line);
			else if (pSpawn->Type == 1)
				sprintf(line, "%s [NPC]", line);
			else if (pSpawn->Type == 2)
				sprintf(line, "%s [corpse]", line);
			else
				sprintf(line, "%s [other - %d]", line, pSpawn->Type);
		}

		// Spawn ID
		if (SortID) {
			sprintf(line, "%s (ID %d)", line, pSpawn->SpawnID);
		}

		printf("%s\n", line);
		totalFound++;
	}

	// Print total
	if  (totalFound == 1) {
		if (SortType == 0) {
			printf("There is %d thing in %s.\n", totalFound, szZone[currentZone]);
		} else if (SortType == 1) {
			printf("There is %d PC in %s.\n", totalFound, szZone[currentZone]);
		} else if (SortType == 2) {
			printf("There is %d pet in %s.\n", totalFound, szZone[currentZone]);
		} else if (SortType == 3) {
			printf("There is %d NPC in %s.\n", totalFound, szZone[currentZone]);
		} else if (SortType == 4) {
			printf("There is %d corpse in %s.\n", totalFound, szZone[currentZone]);
		}
	} else {
		if (SortType == 0) {
			printf("There are %d things in %s.\n", totalFound, szZone[currentZone]);
		} else if (SortType == 1) {
			printf("There are %d PC's in %s.\n", totalFound, szZone[currentZone]);
		} else if (SortType == 2) {
			printf("There are %d pets in %s.\n", totalFound, szZone[currentZone]);
		} else if (SortType == 3) {
			printf("There are %d NPC's in %s.\n", totalFound, szZone[currentZone]);
		} else if (SortType == 4) {
			printf("There are %d corpses in %s.\n", totalFound, szZone[currentZone]);
		}
	}

	return 0;
}