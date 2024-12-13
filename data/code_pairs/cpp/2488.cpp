#include <iostream>
#include <cassert>

// Define a namespace to encapsulate the function, similar to a Fortran module
namespace UpdateDisplNewmarkBackward {

    // Declare the function prototype
    void updateDisplNewmarkBackward(int& value);

} // namespace UpdateDisplNewmarkBackward

// Define the function
void UpdateDisplNewmarkBackward::updateDisplNewmarkBackward(int& value) {
    // Increment the value by 1
    value += 1;
}

// Unit test function
void testUpdateDisplNewmarkBackward() {
    int val = 5;
    UpdateDisplNewmarkBackward::updateDisplNewmarkBackward(val);
    std::cout << "Updated Value: " << val << std::endl;

    // Check if the value is updated correctly
    assert(val == 6);
    std::cout << "Test Passed" << std::endl;
}

int main() {
    testUpdateDisplNewmarkBackward();
    return 0;
}