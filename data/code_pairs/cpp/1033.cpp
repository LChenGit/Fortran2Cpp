// M.hpp
class M {
public:
    static int a;
};

// M.cpp
#include "M.hpp"
int M::a = 0; // Initialization of the static member variable

// main.cpp
#include "M.hpp"
#include <iostream>
#include <cstdlib>

int main() {
    int& local1 = M::a;
    int& local2 = M::a;

    local1 = 5;
    local2 = 3;

    if (local1 == local2) {
        std::cout << "Test passed: local1 and local2 reference the same variable." << std::endl;
    } else {
        std::cout << "Test failed: local1 and local2 do not reference the same variable." << std::endl;
    }

    return 0;
}