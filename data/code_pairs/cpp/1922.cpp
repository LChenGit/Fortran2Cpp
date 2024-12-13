#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

// The test function modifies the string to a predefined value
void test(std::string& a) {
    a = "Sample#2"; // Directly assigning the new value
}

int main() {
    // Initializing a vector as an equivalent to Fortran's character pointer array
    std::vector<char> ptr(9);

    // Using memcpy to copy the string, including the null terminator, into the vector
    std::string sample = "Sample#0";
    std::memcpy(ptr.data(), sample.c_str(), sample.size() + 1);

    // Check if ptr matches the expected sequence
    if (!std::equal(ptr.begin(), ptr.end(), sample.begin())) {
        std::cerr << "Mismatch detected, stopping." << std::endl;
        return 1; // Equivalent to STOP 1 in Fortran
    }

    // Test the functionality that modifies a string
    std::string a = "        "; // Initialize a with 8 spaces
    test(a);

    // Check if 'a' matches the expected value 'Sample#2'
    if (a != "Sample#2") {
        std::cerr << "Mismatch detected in test subroutine, stopping." << std::endl;
        return 2; // Equivalent to STOP 2 in Fortran
    }

    return 0;
}