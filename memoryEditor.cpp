#include <mach/mach_init.h>
#include <mach/mach.h>
#include <stdlib.h>
#include <stdio.h> 
#include <iostream>

bool reading_memory(mach_port_t task,uintptr_t memoryAddress,uintptr_t data_out,uint32_t bytes_read);
int input_type();
bool writing_memory_int(mach_port_t task,uintptr_t memoryAddress,int int_value);

int main(int argc, char* argv[] ){
    kern_return_t ker_ret;
    mach_port_t task;
    uintptr_t data_out;
    uint32_t bytesRead;
    uintptr_t memoryAddress = 0x0;
    int pid;
    int int_value;
    int reason;

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
    if(!reading_memory(task,memoryAddress,data_out,bytesRead)){
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
                if(!reading_memory(task,memoryAddress,data_out,bytesRead)){
                    return 0;
                }
                break;
        }
        std::cout << "Continue? (Q|q to quit): ";
        std::cin >> option;
    }
    return 0;

}

bool reading_memory(mach_port_t task,uintptr_t memoryAddress,uintptr_t data_out,uint32_t bytes_read){    
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


bool writing_memory_int(mach_port_t task,uintptr_t memoryAddress,int int_value){
    int reason;
    std::cout << "Enter new value: " << std::endl;
    std::cin >> int_value;
    if ((reason = vm_write(task, memoryAddress,(uintptr_t) &int_value, sizeof(int))) != KERN_SUCCESS) {
        std::cout << "Failed to write: " << reason << std::endl;
        std::cout << "Exiting Applicatin" << std::endl;
        return false;
    }
    return true;
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