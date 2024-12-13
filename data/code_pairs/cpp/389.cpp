#include <iostream>
#include <cstddef> // For size_t

// The movec function as previously defined
void movec(size_t n, const char* source, char* dest) {
    for(size_t i = 0; i < n; ++i) {
        dest[i] = source[i];
    }
}

int main() {
    const size_t SIZE = 5;
    const char source[SIZE] = {'H', 'e', 'l', 'l', 'o'};
    char dest[SIZE] = {}; // Initialize the destination array

    // Call movec function to copy characters
    movec(SIZE, source, dest);

    // Display dest array
    std::cout << "dest array after movec: ";
    for(size_t i = 0; i < SIZE; ++i) {
        std::cout << dest[i];
    }
    std::cout << std::endl;

    return 0;
}