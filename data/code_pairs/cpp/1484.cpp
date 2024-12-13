#include <iostream>

void mysub() {
    std::cout << "Printing this requires Fortran language libraries" << std::endl;
}

void my_sub() {
    // Does nothing
}

int main() {
    std::cout << "Testing mysub():" << std::endl;
    mysub();
    std::cout << "Test complete. (Manual verification required)" << std::endl;
    std::cout << "Testing my_sub() (No-Op):" << std::endl;
    my_sub();
    std::cout << "Test complete. (Nothing to verify)" << std::endl;
    return 0;
}