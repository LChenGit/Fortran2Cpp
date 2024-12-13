#include <iostream>
#include <cstdlib> // For abort()
#include <vector>

namespace nonF03ComBlock {
double r;
double s;

void hello(std::vector<int>& myArray) {
    r = 1.0;
    s = 2.0;
}
} // End of namespace nonF03ComBlock

int main() {
    using namespace nonF03ComBlock;

    std::vector<int> myArray(10);

    hello(myArray);

    // Test if r and s are set correctly
    if(r == 1.0 && s == 2.0) {
        std::cout << "Test passed: r and s are correctly set." << std::endl;
    } else {
        std::cout << "Test failed: r and s are not correctly set." << std::endl;
        std::abort();
    }

    return 0;
}