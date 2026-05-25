#include <iostream>
#include <fstream>
#include "VM.h"

int main()
{
    // 1. Create a sample assembly file
    std::ofstream testFile("test.asm");
    testFile << "mov r0 42\n";
    testFile << "mov r1 999\n";
    testFile << "mov r7 777\n";
    testFile.close();

    std::cout << "Running NeonVM with test.asm..." << std::endl;

    // 2. Instantiate and run NeonVM
    NeonVM::VM vm;
    vm.run("test.asm");

    // 3. Print result to verify it worked
    vm.printRegisters();

    return 0;
}