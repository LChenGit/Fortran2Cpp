#include <iostream>

// Declaration of init function
void init() {
    std::cout << "Initialization process..." << std::endl;
    // Initialization code here
}

// Declaration of run function
void run() {
    std::cout << "Running process..." << std::endl;
    // Running code here
}

// Declaration of finalize function
void finalize() {
    std::cout << "Finalization process..." << std::endl;
    // Finalization code here
}

int main() {
    init();
    run();
    finalize();
    return 0;
}