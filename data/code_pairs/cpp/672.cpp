#include <iostream>
#include <cassert>

namespace test_block {
    
    int suba() {
        int a = 5;
        {
            int b = a + 2;
            return b; // Return b for testing.
        }
    }

    void subb() {
        // Empty, as in the original Fortran code.
    }

} // end namespace test_block

int main() {
    // Unit test for suba
    assert(test_block::suba() == 7);
    std::cout << "Test for suba passed." << std::endl;

    return 0;
}