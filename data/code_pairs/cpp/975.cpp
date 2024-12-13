#include <cstdlib> // For abort()
#include <cstring> // For strcmp()
#include <iostream>

void testArrayInitialization() {
    long long arr[3] = {4, 42, 12};
    if (arr[0] != 4 || arr[1] != 42 || arr[2] != 12) std::abort();
    
    // Additional tests for array initialization could go here
}

void testCharacterArrayInitialization() {
    char carr[3][7];
    strncpy(carr[0], "foo", 6); carr[0][6] = '\0';
    strncpy(carr[1], "foob", 6); carr[1][6] = '\0'; // "foob" will be stored and compared correctly
    strncpy(carr[2], "xyz", 6); carr[2][6] = '\0';
    
    if (strcmp(carr[0], "foo") != 0 || strcmp(carr[1], "foob") != 0 || strcmp(carr[2], "xyz") != 0) {
        std::abort();
    }
    
    // Additional tests for character array initialization could go here
}

int main() {
    testArrayInitialization();
    testCharacterArrayInitialization();
    std::cout << "All tests passed." << std::endl;
    return 0;
}