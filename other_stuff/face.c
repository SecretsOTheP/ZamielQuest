#include <stdio.h>
#include "eq_data.h"
#include "mem.c"

void error(char *msg) {
        printf("error: %s\n",msg);
        exit(1);
}

int main(int argc, char **argv) {
	int pid;
	float heading;
	mach_port_t task;
	kern_return_t err;
	PSPAWNINFO pSpawn;
	DWORD address;

	if (argc < 3) {
		printf("usage: %s <pid> <heading>\n", argv[0]);
		return 1;
	}

	pid = atoi(argv[1]);
	heading = atof(argv[2]);

	// Make sure we're root
	if (getuid() && geteuid())
		error("requires root");

	// Get the task port
	err = task_for_pid(mach_task_self(), pid, &task);
	if ((err != KERN_SUCCESS) || !MACH_PORT_VALID(task))
		error("getting eq task");

	// Set heading
	address = *mem_read(task, _LocalPlayer, 4);
	pSpawn = (PSPAWNINFO)mem_read(task, address, sizeof(SPAWNINFO));
	heading *= 1.42222222222;
	pSpawn->Heading = heading;
	mem_write(task, address, (PDWORD)pSpawn, sizeof(SPAWNINFO));
}