#pragma once
#include <mach/mach_init.h>
#include <mach/mach.h>
#include <stdlib.h>
#include <stdio.h> 
#include <iostream>
#include "MemoryFunctions.hpp"

bool writing_memory_int(mach_port_t task,uintptr_t memoryAddress,int int_value){
    int reason;
    std::cout << "Enter new value in Hex: " << std::endl;
    std::cin >> int_value;
    if ((reason = vm_write(task, memoryAddress,(uintptr_t) &int_value, sizeof(int))) != KERN_SUCCESS) {
        std::cout << "Failed to write: " << reason << std::endl;
        std::cout << "Exiting Applicatin" << std::endl;
        return false;
    }
    return true;
}