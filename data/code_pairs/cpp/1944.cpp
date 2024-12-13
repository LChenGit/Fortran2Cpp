#include <iostream>
#include <openacc.h>

extern "C" void oacc1() {
    const int a = 1;
    #pragma acc declare device_resident(a)
    #pragma acc parallel loop
    for(int i = 0; i < 5; ++i) {
        // This loop is symbolic and doesn't perform any operations
    }
}

int main() {
    oacc1();
    std::cout << "C++ Stdout: Test Passed." << std::endl;
    return 0;
}