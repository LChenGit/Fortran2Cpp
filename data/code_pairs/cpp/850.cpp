#include <iostream>

void check(int &min, int &max, int i) {
    if (min < 1) min = 1;
    if (max > i) max = i;
    if (max < min) max = min;
}

int main() {
    int min, max, i;

    // Test case 1
    min = 0; max = 10; i = 5;
    check(min, max, i);
    std::cout << "Test 1: MIN=" << min << " MAX=" << max << std::endl;

    // Test case 2
    min = -1; max = 6; i = 5;
    check(min, max, i);
    std::cout << "Test 2: MIN=" << min << " MAX=" << max << std::endl;

    // Test case 3
    min = 2; max = 1; i = 3;
    check(min, max, i);
    std::cout << "Test 3: MIN=" << min << " MAX=" << max << std::endl;

    return 0;
}