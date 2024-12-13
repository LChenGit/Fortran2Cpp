#include <iostream>

namespace m11 {
    int add_two_numbers(int a, int b) {
        return a + b;
    }
}

int main() {
    int result = m11::add_two_numbers(2, 3);

    std::cout << "Testing add_two_numbers with inputs 2 and 3. ";
    if (result == 5) {
        std::cout << "Test passed. Result is: " << result << std::endl;
    } else {
        std::cout << "Test failed. Result is: " << result << std::endl;
    }

    return 0;
}