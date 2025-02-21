#include <iostream>
#include <cassert>

int BKKCRYPT(int X) {
    return X;
}

int main() {
    int TEST1IN = 255;
    int TEST1OUT = BKKCRYPT(TEST1IN);
    
    // Unit test check
    assert(TEST1IN == TEST1OUT && "Test case failed: assertion failed");
    
    std::cout << "TEST PASSED" << std::endl;
    return 0;
}