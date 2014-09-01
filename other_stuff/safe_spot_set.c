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
	float* SafeSpotX = (float*)malloc(sizeof(float*));
	float* SafeSpotY = (float*)malloc(sizeof(float*));
	float* SafeSpotZ = (float*)malloc(sizeof(float*));

	if (argc < 5) {
		printf("usage: %s <pid> <SafeX> <SafeY> <SafeZ>\n", argv[0]);
		return 1;
	}

	pid = atoi(argv[1]);
	*SafeSpotX = atof(argv[2]);
	*SafeSpotY = atof(argv[3]);
	*SafeSpotZ = atof(argv[4]);

	// Make sure we're root
	if (getuid() && geteuid())
		error("requires root");

	// Get the task port
	err = task_for_pid(mach_task_self(), pid, &task);
	if ((err != KERN_SUCCESS) || !MACH_PORT_VALID(task))
		error("getting eq task");

	// Set safe spot
	mem_write(task, _SafeSpot, (PDWORD)SafeSpotX, sizeof(float*));
	mem_write(task, _SafeSpot + 4, (PDWORD)SafeSpotY, sizeof(float*));
	mem_write(task, _SafeSpot + 8, (PDWORD)SafeSpotZ, sizeof(float*));
}