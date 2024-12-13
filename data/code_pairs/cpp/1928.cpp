#include <iostream>
#include <vector>

void checkVector(const std::vector<std::vector<int>>& vec) {
    std::cout << "Is empty: " << std::boolalpha << vec.empty() << std::endl;
}

int main() {
    std::vector<std::vector<int>> j;

    // Check if 'j' vector (2D array) is empty before allocation
    std::cout << "Before allocation: ";
    checkVector(j);
    
    // "Allocate" the vector by adding a sub-vector
    j.push_back(std::vector<int>{1, 2, 3});
    
    // Check again after "allocation"
    std::cout << "After allocation: ";
    checkVector(j);

    return 0;
}