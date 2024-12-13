#include <iostream>

void check(int iresult, int ians, int& error) {
    if (iresult != ians) {
        error += 1;
    }
}

int main() {
    int error;

    // Test 1
    error = 0;
    check(5, 5, error);
    if (error == 0) {
        std::cout << "Test 1 passed." << std::endl;
    } else {
        std::cout << "Test 1 failed." << std::endl;
    }

    // Test 2
    error = 0;
    check(3, 4, error);
    if (error == 1) {
        std::cout << "Test 2 passed." << std::endl;
    } else {
        std::cout << "Test 2 failed." << std::endl;
    }

    return 0;
}