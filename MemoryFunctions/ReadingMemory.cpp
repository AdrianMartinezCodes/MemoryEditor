#pragma once
#include <mach/mach_init.h>
#include <mach/mach.h>
#include <stdlib.h>
#include <stdio.h> 
#include <iostream>
#include "MemoryFunctions.hpp"

bool reading_memory_int(mach_port_t task,uintptr_t memoryAddress,uintptr_t data_out,uint32_t bytes_read){    
    int reason;
    if ((reason = vm_read(task, memoryAddress,sizeof(int),&data_out,&bytes_read ))!= KERN_SUCCESS) {
        std::cout << "Failed to read "<< reason << std::endl;
        std::cout << "Exiting application." << std::endl;
        return false;
    }
    else{
        std::cout << "Successful Read" << std::endl;
        //Results
        std::cout << "Value at 0x" << std::hex << std::uppercase << memoryAddress << " :" ;
        std::cout << *(int*) data_out << std::endl;
    }
    return true;
}
