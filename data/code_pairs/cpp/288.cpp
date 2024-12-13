#include <iostream>
#include <vector>
#include <string>
#include <cassert>

// Function performing the substring operation
void performSubstringOperation(std::vector<std::string>& strings, std::vector<std::string>& substrings) {
    for (int i = 0; i < 2; ++i) {
        substrings[i] = strings[i].substr(1, 5); // Take 5 characters starting from index 1
    }
}

// Test function for the performSubstringOperation
void testPerformSubstringOperation() {
    std::vector<std::string> strings = {"abcdefghij", "klmnopqrst"};
    std::vector<std::string> substrings(10, std::string(5, ' ')); // Initializing with 10 strings of length 5

    performSubstringOperation(strings, substrings);

    assert(substrings[0] == "bcdef" && "Substring operation failed for element 0.");
    assert(substrings[1] == "lmnop" && "Substring operation failed for element 1.");

    std::cout << "All tests passed successfully." << std::endl;
}

int main() {
    // Perform any main program logic here if needed

    // Running the tests
    testPerformSubstringOperation();

    return 0;
}