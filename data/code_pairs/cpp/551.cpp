#include <iostream>
#include <string>
#include <vector>

int main() {
    const int N = 1; // Matching the Fortran behavior of single characters
    std::vector<std::string> C(3, std::string(N, 'a')); // Initialize vector with 'a'
    std::string D = std::string(N, 'a'); // Initialize string D with 'a'

    for(const auto& str : C) {
        std::cout << str << std::endl; // Print each string in the vector
    }
    std::cout << D << std::endl; // Print string D

    return 0;
}