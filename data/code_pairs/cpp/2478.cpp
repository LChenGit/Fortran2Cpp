#include <iostream>
#include <array>

void HEX_NODES(std::array<int, 27>& IADDX, std::array<int, 27>& IADDY, std::array<int, 27>& IADDZ) {
    for (int i = 0; i < 27; ++i) {
        IADDX[i] += 1;
        IADDY[i] += 1;
        IADDZ[i] += 1;
    }
}

int main() {
    std::array<int, 27> IADDX;
    std::array<int, 27> IADDY;
    std::array<int, 27> IADDZ;

    for (int i = 0; i < 27; ++i) {
        IADDX[i] = i + 1; // Adjusted to match Fortran's 1-based indexing
        IADDY[i] = (i + 1) * 2; // Same adjustment
        IADDZ[i] = (i + 1) * 3; // Same adjustment
    }

    HEX_NODES(IADDX, IADDY, IADDZ);

    std::cout << "IADDX: ";
    for (const auto& val : IADDX) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "IADDY: ";
    for (const auto& val : IADDY) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "IADDZ: ";
    for (const auto& val : IADDZ) std::cout << val << " ";
    std::cout << std::endl;

    return 0;
}