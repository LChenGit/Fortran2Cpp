#include <iostream>

void test_i(int i[], int size) {
    if (i[0] == 1) {
        std::cout << "Test 1 passed." << std::endl;
    } else {
        std::cout << "Test 1 failed." << std::endl;
    }

    if (i[1] == 2) {
        std::cout << "Test 2 passed." << std::endl;
    } else {
        std::cout << "Test 2 failed." << std::endl;
    }
}

int main() {
    int i[2];
    const int j = 1;
    i[0] = 1; // Adjusted to 0-based indexing for C++
    i[j] = 2; // Directly using `j` since it represents the next index
    test_i(i, 2);
    return 0;
}