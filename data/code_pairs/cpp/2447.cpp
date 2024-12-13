#include <iostream>
#include <vector>

struct MyType {
    std::vector<int> indices;
};

int main() {
    MyType object;

    // Simulating a single "process" scenario, akin to Fortran's 'this_image()' for standalone examples.
    int me = 1; // Normally, this would be dynamically determined in a parallel environment.

    // Fill the vector.
    for (int i = 1; i <= me; ++i) {
        object.indices.push_back(i);
    }

    // Perform checks.
    if (object.indices.size() != 1) {
        std::cerr << "Error: Size of indices is not 1." << std::endl;
        return 1; // Error exit.
    }

    if (object.indices[0] != 1) {
        std::cerr << "Error: First element of indices is not 1." << std::endl;
        return 1; // Error exit.
    }

    std::cout << "C++ Unit Test Passed Successfully." << std::endl;
    return 0; // Success exit.
}