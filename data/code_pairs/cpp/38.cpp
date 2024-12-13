// File: AAP.cpp
#include <iostream>
#include <vector>

void AAP(std::vector<int>& NOOT) {
    std::cout << "C++ function AAP called with an array of size " << NOOT.size() << std::endl;
}

int main() {
    std::vector<int> testVector(5);
    AAP(testVector);
    return 0;
}