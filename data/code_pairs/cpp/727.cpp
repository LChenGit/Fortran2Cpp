#include <algorithm>
#include <iostream>
#include <vector>

void izero(std::vector<int>& ia) {
    std::fill(ia.begin(), ia.end(), 0);
}

int main() {
    bool test_passed = true;
    std::vector<int> test_array = {1, 2, 3, 4, 5};

    izero(test_array);

    for (int val : test_array) {
        if (val != 0) {
            test_passed = false;
            break;
        }
    }

    if (test_passed) {
        std::cout << "Test Passed." << std::endl;
    } else {
        std::cout << "Test Failed." << std::endl;
    }

    return 0;
}