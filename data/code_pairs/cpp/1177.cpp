#include <iostream>
#include <array>
#include <sstream> // For std::ostringstream
#include <cassert> // For assert()

int main() {
    std::array<int, 2> nums1 = {11, 17};
    std::array<int, 2> nums2 = {19, 23};

    std::ostringstream test_output;
    for (int i = 0; i < 2; ++i) {
        test_output.width(3); // To mimic the Fortran output formatting
        test_output << nums1[i] + nums2[i] << " ";
    }

    std::string expected_output = " 30  40 ";
    // Use the test output for validation
    assert(test_output.str() == expected_output && "Test Failed!");

    // If the program reaches this point, the test passed successfully
    std::cout << "Test Passed!" << std::endl;

    return 0;
}