#pragma once
#include <mach/mach_init.h>
#include <mach/mach.h>
#include <stdlib.h>
#include <stdio.h> 
#include <iostream>
bool reading_memory(mach_port_t task, uintptr_t memoryAddress, uintptr_t data_out, uint32_t bytes_read);
bool writing_memory(mach_port_t task, uintptr_t memoryAddress, int int_value);
bool writing_memory(mach_port_t task, uintptr_t memoryAddress, std::string string_value);
bool writing_memory(mach_port_t task, uintptr_t memoryAddress, char char_val);