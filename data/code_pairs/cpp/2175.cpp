#include <iostream>
#include <cstring>
#include <cstdlib>

struct Block {
    int d, e;
    float f;
} block = {42, 43, 2.0f};

struct Block2 {
    char s[16];
} block2 = {"Hello World    "};

void test() {
    if (block.d != 42 || block.e != 43 || block.f != 2.0f) {
        std::cerr << "Test failed due to incorrect values in block" << std::endl;
        std::exit(1);
    }
    if (std::strncmp(block2.s, "Hello World    ", 15) != 0) {
        std::cerr << "Test failed due to incorrect value in block2" << std::endl;
        std::exit(1);
    }
    std::cout << "All tests passed." << std::endl;
}

int main() {
    test();
    return 0;
}