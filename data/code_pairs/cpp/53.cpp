#include <iostream>
#include <cmath>

bool gtabs_int(int x, int y) {
    return std::abs(x) > std::abs(y);
}

int main() {
    std::cout << "Test 1 (3, -4): " << gtabs_int(3, -4) << std::endl;  // Expected: 0 (false)
    std::cout << "Test 2 (-5, 2): " << gtabs_int(-5, 2) << std::endl;  // Expected: 1 (true)
    std::cout << "Test 3 (-2, -3): " << gtabs_int(-2, -3) << std::endl;  // Expected: 0 (false)
    std::cout << "Test 4 (0, 0): " << gtabs_int(0, 0) << std::endl;    // Expected: 0 (false)
    
    return 0;
}