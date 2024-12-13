#include <iostream>
#include <cstdlib> // for exit

void foo(void* a, size_t size) {
    int i;
    if (size != sizeof(i)) {
        std::cerr << "Test failed: size mismatch, stopping program." << std::endl;
        exit(1);
    }
}

int main() {
    int z = 0;
    foo(&z, sizeof(z));
    std::cout << "Test passed: foo(&z, sizeof(z)) executed successfully" << std::endl;
    return 0;
}