#include <iostream>
#include <cstring>
#include <cassert>

int main() {
    const char a[3] = "12"; // Plus one for the null terminator
    char b[5] = "";         // Initialize with empty string, plus one for the null terminator

    std::strncpy(b, a, 4);  // Copying 'a' into 'b'
    b[4] = '\0';            // Ensure null termination, though not strictly necessary here due to initialization

    // Output the values
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    // Assertions to verify correctness
    assert(std::strcmp(a, "12") == 0 && "Test failed: a is not '12'");
    assert(std::strcmp(b, "12") == 0 && "Test failed: b is not '12'");

    std::cout << "All tests passed." << std::endl;

    return 0;
}