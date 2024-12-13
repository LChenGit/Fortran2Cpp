#include <iostream>
#include <cassert>

int main() {
    const int n = 2;
    int a[n];
    int* ptr = nullptr;
    ptr = a; // pointing ptr to the start of array a

    a[0] = 0;
    ptr[0] = 1; // modifying the first element of a through ptr

    // Test
    assert(a[0] == 1);
    std::cout << "Test Passed." << std::endl;

    return 0;
}