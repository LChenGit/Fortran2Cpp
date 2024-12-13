// main_program.cpp
#include <iostream>
#include <vector>

int main() {
    static std::vector<int> itmp(3); // Mimicking 'save' attribute
    itmp[0] = 3; // Arrays in C++ are 0-indexed
    if (itmp.size() == 3 && itmp[0] == 3) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "NG: itmp(3) is illegally allocated or not allocated." << std::endl;
    }
    return 0;
}