#include <vector>
#include <string>
#include <iostream>

// Function prototype
void S(std::vector<std::string>& x);

int main() {
    std::vector<std::string> X1 = {"Test1", "Test2"};

    // Call the function with the vector
    S(X1);

    // Print the results
    for (const auto& str : X1) {
        std::cout << str << std::endl;
    }

    return 0;
}

// Function definition that mimics the SUBROUTINE S from Fortran
void S(std::vector<std::string>& x) {
    for (auto& str : x) {
        str += "_suffix";
    }
}