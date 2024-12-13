#include <iostream>

void hoge(int l1 = 1, int k = 0) {
    int m = 1;
    if (l1 >= 1 && l1 <= 4) {
        m = l1;
    }
    std::cout << "m = " << m << std::endl;
}

int main() {
    // Directly using the hoge function to simulate test cases
    std::cout << "Test 1 (Expect m=1): ";
    hoge(0, 0);  // m should be 1 by default

    std::cout << "Test 2 (Expect m=2): ";
    hoge(2, 0);  // m should be set to 2

    std::cout << "Test 3 (Expect m=1): ";
    hoge(5, 0);  // m should remain 1 since l1 is outside the range

    return 0;
}