#include <iostream>
#include <string>
#include <cstdlib> // For std::exit()
#include <cstdint> // For std::int16_t

namespace defs_basis {

using i1b = std::int16_t; // Assuming i1b corresponds to a 2-byte integer

int get_reclen(const std::string& str) {
    if (str == "i1b" || str == "I1B") {
        // Using sizeof to determine the size in bytes
        return sizeof(i1b);
    } else {
        std::cerr << "Unknown kind: " << str << std::endl;
        std::exit(1);
    }
}

} // namespace defs_basis

int main() {
    int expected_rcl = 2; // Adjusted to match the Fortran test expectation
    int actual_rcl = defs_basis::get_reclen("i1b");

    if (actual_rcl == expected_rcl) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cerr << "Test failed: Expected " << expected_rcl << " but got " << actual_rcl << std::endl;
    }

    return 0;
}