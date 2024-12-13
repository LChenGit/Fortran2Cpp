#include <iostream>

namespace test { 

    void oacc1(int& result) { 
        int i;
        float pointee; // Included to mirror the Fortran pointer example, though unused in this specific test.
        float* ptr = &pointee; // Pointer declaration to mirror Fortran example, though unused.

        result = 0;
        for(i = 1; i <= 5; i++) {
            result += i;
        }
    }

}

int main() {
    int result;
    test::oacc1(result);
    if (result == 15) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }
    return 0;
}