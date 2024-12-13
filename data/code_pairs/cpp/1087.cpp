#include <iostream>

int modf(int m, int ix) {
    int ia = 0;
    if (ix <= 0) ia = m;
    int result = ix + ia - (static_cast<int>((ix + ia - 1) / m)) * m;
    if (result < 1) result += m;
    
    return result;
}

int main() {
    // Test cases
    std::cout << "Test 1: Expected 1, got " << modf(3, 4) << std::endl;
    std::cout << "Test 2: Expected 5, got " << modf(5, -1) << std::endl;
    std::cout << "Test 3: Expected 7, got " << modf(10, 27) << std::endl;
    std::cout << "Test 4: Expected 1, got " << modf(1, 0) << std::endl;

    return 0;
}