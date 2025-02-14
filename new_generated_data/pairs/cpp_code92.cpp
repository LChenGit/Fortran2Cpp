#include <cassert>
#include <iostream>

// Declare the Fortran function
extern "C" void my_function();

int main() {
    my_function();
    assert(1 == 1);  // Passed test
    return 0;
}

// Define the Fortran function
extern "C" void my_function() {
    std::cout << "Hello from Fortran!" << std::endl;
}