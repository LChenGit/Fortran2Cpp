#include<iostream>

void mysub(double a, double b, double& c, double& d) {
    c = a + b;
    d = a - b;
}

int main() {
    double a, b, c, d;

    // Test case 1
    a = 5.0; b = 3.0;
    mysub(a, b, c, d);
    if (c == 8.0 && d == 2.0) {
        std::cout << "Test 1 passed." << std::endl;
    } else {
        std::cout << "Test 1 failed." << std::endl;
    }

    // Test case 2
    a = -1.0; b = -2.0;
    mysub(a, b, c, d);
    if (c == -3.0 && d == 1.0) {
        std::cout << "Test 2 passed." << std::endl;
    } else {
        std::cout << "Test 2 failed." << std::endl;
    }

    return 0;
}