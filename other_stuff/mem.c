#include <stdlib.h>
#include <mach/mach_traps.h>
#include <mach/mach_init.h>
#include <mach/mach_error.h>
#include <mach/mach.h>
#include <mach/mach_types.h>
#include <mach/i386/thread_status.h>

unsigned int* mem_read(vm_map_t task, vm_address_t address, vm_size_t size) {
	unsigned int* buffer;
	vm_size_t actualSize;
	kern_return_t result;

	// create a local block to hold the incoming data
	buffer = malloc((size_t)size);
	if (!buffer) {
		// no buffer, abort
		exit(-1);
	}

	// perform the read
	result = mach_vm_read_overwrite(task, address, size, buffer, &actualSize);
	if (result != KERN_SUCCESS) {
		// read error, abort
		free(buffer);
		return NULL;
	}
	return buffer;
}

int mem_write(vm_map_t task, vm_address_t address, unsigned int* data, vm_size_t size) {
	vm_size_t actualSize;
	kern_return_t result;

	result = mach_vm_write(task, address, (vm_offset_t)data, size);
	if (result != KERN_SUCCESS) {
		return 1;
	}
	return 0;
}