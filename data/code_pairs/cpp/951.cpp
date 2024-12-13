#include <array>
#include <iostream>
#include <cassert>

std::array<int, 100> IPARMS;  // Global array to mimic COMMON block

void XLAENV(int ISPEC, int NVALUE) {
    if (ISPEC >= 1 && ISPEC <= 9) {
        IPARMS[ISPEC - 1] = NVALUE;  // Adjusted for 0-based indexing
    }
}

int main() {
    std::cout << "Testing XLAENV..." << std::endl;

    XLAENV(1, 10);
    XLAENV(5, 50);
    XLAENV(9, 90);

    assert(IPARMS[0] == 10);
    assert(IPARMS[4] == 50);
    assert(IPARMS[8] == 90);

    std::cout << "IPARMS[0]: " << IPARMS[0] << std::endl;
    std::cout << "IPARMS[4]: " << IPARMS[4] << std::endl;
    std::cout << "IPARMS[8]: " << IPARMS[8] << std::endl;

    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}