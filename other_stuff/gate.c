#include <stdio.h>
#include "eq_data.h"
#include "mem.c"

void error(char *msg) {
        printf("error: %s\n",msg);
        exit(1);
}

int main(int argc, char **argv) {
	int pid;
	mach_port_t task;
	kern_return_t err;
	PSPAWNINFO pSpawn;
	DWORD address;

	if (argc < 2) {
		printf("usage: %s <pid>\n", argv[0]);
		return 1;
	}

	pid = atoi(argv[1]);

	// Make sure we're root
	if (getuid() && geteuid())
		error("requires root");

	// Get the task port
	err = task_for_pid(mach_task_self(), pid, &task);
	if ((err != KERN_SUCCESS) || !MACH_PORT_VALID(task))
		error("getting eq task");

	// Gate
	address = *mem_read(task, _LocalPlayer, 4);
	pSpawn = (PSPAWNINFO)mem_read(task, address, sizeof(SPAWNINFO));
	pSpawn->Type = 2;
	mem_write(task, address, (PDWORD)pSpawn, sizeof(SPAWNINFO));
}