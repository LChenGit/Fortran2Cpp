#include <iostream>
#include <string>
#include <omp.h>
#include <cassert>

void foo(const std::string& x, std::string& result) {
    #pragma omp master
    {
        result = x;
        auto firstNotSpace = result.find_first_not_of(' ');
        if (firstNotSpace != std::string::npos) {
            result.erase(0, firstNotSpace); // Adjust left
        } else {
            result.clear(); // if no non-space character, clear the result
        }
    }
}

int main() {
    std::string input = "   example";
    std::string result;
    std::string expected = "example";

    foo(input, result);

    // Check if result matches expected
    assert(result == expected && "Test failed.");

    std::cout << "C++ Test passed." << std::endl;
    return 0;
}