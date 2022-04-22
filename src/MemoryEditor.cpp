#include <mach/mach_init.h>
#include <mach/mach.h>
#include <stdlib.h>
#include <stdio.h> 
#include <iostream>
#include <string>
#include "MemoryEditorConfig.h"
#include "MemoryFunctions.hpp"


int input_type();

int main(int argc, char* argv[] ){
    kern_return_t ker_ret;
    mach_port_t task;
    uintptr_t data_out;
    uint32_t bytesRead;
    uintptr_t memoryAddress = 0x0;
    int pid;
    int int_value;
    int reason;

    // report version
    std::cout << "MemoryEditor" << " Version " << MemoryEditor_VERSION_MAJOR << "." 
    <<  MemoryEditor_VERSION_MINOR << std::endl;

    //Grabbing task for pid
    std::cout << "Enter pid: ";
    std::cin >> pid;
    ker_ret = task_for_pid(mach_task_self(), pid, &task);
    if (ker_ret!=KERN_SUCCESS)
    {
        std::cout << "task_for_pid() failed: " << mach_error_string(ker_ret) << std::endl;
        std::cout << "Exiting application." << std::endl;
        return 0;
    } else {
        std::cout << "task_for_pid() successful" << std::endl;
    }
    //input a known memory address
    std::cout << "Type in memory location: ";
    std::cin >> std::hex >> memoryAddress;
    std::cout << "Reading 0x" << std::hex << std::uppercase << memoryAddress << " ..." << std::endl;
    //reading from PID at memory address
    if(!reading_memory_int(task,memoryAddress,data_out,bytesRead)){
        return 0;
    }
    //change value at memory location
    char option = ' ';
    while(option != 'q' && option != 'Q'){
        int select;
        select = input_type();
        switch(select){
            case 0:
                if(!writing_memory_int(task, memoryAddress,(uintptr_t) int_value)){
                    return 0;
                }
                std::cout << "Successful write" << std::endl;
                if(!reading_memory_int(task,memoryAddress,data_out,bytesRead)){
                    return 0;
                }
                break;
        }
        std::cout << "Continue? (Q|q to quit): ";
        std::cin >> option;
    }
    return 0;

}

int input_type(){
    int type = -1;
    std::cout << "Which data type? (Supported Options: 0 - int)" << std::endl;
    std::cin >> type;
    while(!std::cin || type != 0){
            std::cout << "Invalid input" << std::endl;
            std::cin.clear();
            std::cin.ignore();
            std::cin >> type;
    }
    return type;
}