#pragma once
#include <mach/mach_init.h>
#include <mach/mach.h>
#include <stdlib.h>
#include <stdio.h> 
#include <iostream>
bool reading_memory_int(mach_port_t task,uintptr_t memoryAddress,uintptr_t data_out,uint32_t bytes_read);
bool writing_memory_int(mach_port_t task,uintptr_t memoryAddress,int int_value);