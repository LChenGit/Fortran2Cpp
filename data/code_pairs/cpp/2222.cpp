#include <iostream>

// Define the type1 structure
struct type1 {
    int x;
};

// Define a global variable of type type1
type1 pdm_bps;

// Initialize the global variable
struct GlobalInitializer {
    GlobalInitializer() {
        pdm_bps.x = 10;
    }
} globalInitializer;

// Program main
int main() {
    std::cout << "pdm_bps.x = " << pdm_bps.x << std::endl;
    return 0;
}