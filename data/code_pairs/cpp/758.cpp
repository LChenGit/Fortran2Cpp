#include <iostream>
#include <cmath>
#include <iomanip> // For std::setprecision

float specific__tanh_r4(float parm) {
    return std::tanh(parm);
}

int main() {
    // Setting precision for floating-point output
    std::cout << std::fixed << std::setprecision(6);

    // Test cases
    float test_val = 0.0f;
    std::cout << "tanh(" << test_val << ") = " << specific__tanh_r4(test_val) << std::endl;

    test_val = 1.0f;
    std::cout << "tanh(" << test_val << ") = " << specific__tanh_r4(test_val) << std::endl;

    test_val = -1.0f;
    std::cout << "tanh(" << test_val << ") = " << specific__tanh_r4(test_val) << std::endl;

    return 0;
}