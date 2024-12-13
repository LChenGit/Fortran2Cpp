#include <iostream>
#include <cstring>
#include <cstdlib>

char chr[9]; // Global variable for the common block

extern "C" void foobar1() {
    std::strncpy(chr, "foobar1", 8);
    chr[8] = '\0'; // Ensure null termination
}

extern "C" void foobar2() {
    std::strncpy(chr, "foobar2", 8);
    chr[8] = '\0'; // Ensure null termination
}

typedef void (*FuncPtr)();

extern "C" void foo(FuncPtr fcn) {
    fcn();
}

void testChr(const char* expected) {
    if (std::strcmp(chr, expected) != 0) {
        std::cout << "Test Failed: Expected " << expected << " but got " << chr << std::endl;
    } else {
        std::cout << "Test Passed: " << expected << std::endl;
    }
}

int main() {
    chr[0] = '\0';

    foo(foobar1);
    testChr("foobar1");

    foo(foobar2);
    testChr("foobar2");

    return 0;
}