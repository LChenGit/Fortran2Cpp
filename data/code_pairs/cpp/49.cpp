#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

namespace foo {
    int i;
}

namespace bar {
    void baz(std::vector<int>& j) {
        if (j.size() != static_cast<size_t>(foo::i)) {
            std::cerr << "Array length mismatch." << std::endl;
            std::exit(1);
        }

        for (int n = 0; n < foo::i; ++n) {
            if (j[n] != std::pow(n + 1, 2)) {
                std::cerr << "Condition failed." << std::endl;
                std::exit(1);
            }
        }
        std::cout << "Test Passed. Size: " << foo::i << std::endl;
    }
}

void testBaz(const std::vector<int>& testVector, int expectedSize) {
    foo::i = expectedSize;
    bar::baz(const_cast<std::vector<int>&>(testVector)); // For compatibility with this example
}

int main() {
    // Test cases
    std::vector<int> test1 = {1, 4};
    testBaz(test1, 2);

    std::vector<int> test2 = {1, 4, 9};
    testBaz(test2, 3);

    return 0;
}