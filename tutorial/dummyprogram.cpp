#include <string.h>
#include <iostream>
#include <sys/proc.h>

int main(){
    int varInt = 123456;
    std::string varString = "Default String";
    char varCh = 'a';
    char arrChar[128] = "Long char array right there ->";
    int* ptr2int = &varInt;
    int** ptr2ptr = &ptr2int;
    int*** ptr2ptr2 = &ptr2ptr;
    char choice;
    while(true){
        int proc_selfpid(void);
        std::cout << "varInt  " << &varInt << " = " << varInt << std::endl;
        std::cout << "varString  " << &varString << " = " << varString << std::endl;
        std::cout << "char  " << static_cast<void *> (&varCh) << " = " << varCh << std::endl;
        std::cout << "charArr " << &arrChar << " = " << arrChar << std::endl;
        std::cout << "ptr2int  " << &ptr2int << " = " << ptr2int << std::endl;
        std::cout << "ptr2ptr  " << &ptr2ptr << " = " << ptr2ptr << std::endl;
        std::cout << "ptr2ptr2  " << &ptr2ptr2 << " = " << ptr2ptr2 << std::endl;
        std::cout << "Press ENTER to print again." << std::endl;
        std::cin.get();
        std::cout << "------------------" << std::endl;
    }
    return 0;
}