#include <cmath>
#include <iostream>

float specific_sqrt_r4(float parm) {
    return std::sqrt(parm);
}

bool test_specific_sqrt_r4(float input, float expected) {
    float result = specific_sqrt_r4(input);
    if (std::fabs(result - expected) < 1.0E-6) {
        return true;
    } else {
        return false;
    }
}

int main() {
    bool all_tests_passed = true;
    
    all_tests_passed &= test_specific_sqrt_r4(4.0f, 2.0f);
    all_tests_passed &= test_specific_sqrt_r4(9.0f, 3.0f);
    all_tests_passed &= test_specific_sqrt_r4(0.0f, 0.0f);
    
    if (all_tests_passed) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }
    
    return !all_tests_passed;
}