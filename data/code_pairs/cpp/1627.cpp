#include <iostream>

// Function prototype
void dummyUpdate(long& extrastate);

int main() {
    long extrastate = 0; // Using 'long' to ensure compatibility

    // Call the dummy update function with extrastate
    dummyUpdate(extrastate);

    // Print extrastate value after calling dummyUpdate
    std::cout << "Extrastate: " << extrastate << std::endl;

    return 0;
}

// Dummy update function definition
void dummyUpdate(long& extrastate) {
    // This function currently does nothing
}