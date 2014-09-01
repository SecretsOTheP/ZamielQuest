#include <stdio.h>
#include "eq_data.h"
#include "mem.c"

void error(char *msg) {
        printf("error: %s\n",msg);
        exit(1);
}

int main(int argc, char **argv) {
	int pid;
	char* string;
	char null = '\0';
	mach_port_t task;
	kern_return_t err;

	if (argc < 3) {
		printf("usage: %s <pid> <string>\n", argv[0]);
		return 1;
	}

	pid = atoi(argv[1]);
	string = argv[2];

	// Make sure we're root
	if (getuid() && geteuid())
		error("requires root");

	// Get the task port
	err = task_for_pid(mach_task_self(), pid, &task);
	if ((err != KERN_SUCCESS) || !MACH_PORT_VALID(task))
		error("getting eq task");

	// Load the string
	mem_write(task, 0x1900000, (PDWORD)string, strlen(string));
	mem_write(task, 0x1900000 + strlen(string), (PDWORD)&null, 1);
}