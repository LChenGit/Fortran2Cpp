// test_cpp.cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::find
#include <cassert> // For assert

int main() {
    std::vector<std::string> z;
    z.push_back("ab"); // Initial population of the vector
    z.push_back("xy");
    
    z = {z[1]}; // Keeping only the second element, which is 'xy'.

    // Check: Assert if all elements are "xy"
    bool allEqual = true;
    for(const auto& elem : z) {
        if(elem != "xy") {
            allEqual = false;
            break;
        }
    }

    // Using assert to ensure the condition is met
    assert(allEqual == true);

    std::cout << "Test Passed: All elements are 'xy'" << std::endl;

    return 0;
}