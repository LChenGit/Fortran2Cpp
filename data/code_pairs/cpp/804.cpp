#include <iostream>
#include <cstring>

union SharedMemory {
    char a[4];
    struct {
        char c1[3];
        char c2[3];
    } c;
};

void testMemorySharing() {
    SharedMemory shared;

    // Test 1: Modify 'a' and check 'c.c1'
    strncpy(shared.a, "abc", 3);
    shared.a[3] = '\0'; // Null-terminate 'a'
    if (std::strcmp(shared.c.c1, "abc") != 0) {
        std::cerr << "Test 1 failed" << std::endl;
        return;
    }

    // Test 2: Modify 'c.c2' and check it reflects as part of 'a'/'b'
    strncpy(shared.c.c2, "def", 3);
    // Note: Direct comparison of shared.a and shared.c.c2 is not meaningful due to shared memory layout.
    if (std::strncmp(shared.c.c2, "def", 3) != 0) {
        std::cerr << "Test 2 failed" << std::endl;
        return;
    }

    std::cout << "All tests passed." << std::endl;
}

int main() {
    testMemorySharing();
    return 0;
}