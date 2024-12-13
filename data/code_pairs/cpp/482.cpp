#include <iostream>
#include <iomanip>

void banner(int ivery, int iverm, int iverd) {
    std::cout << "********************************************************" << std::endl;
    std::cout << "******************       GOTIC2       ******************" << std::endl;
    std::cout << "****************** Version "
              << std::setw(4) << ivery << '.'
              << std::setfill('0') << std::setw(2) << iverm << '.'
              << std::setw(2) << iverd
              << " ******************" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << "********************************************************" << std::endl;
    std::cout << " " << std::endl;
}

int main() {
    // Call the banner function with test version numbers
    banner(2023, 4, 15);

    return 0;
}