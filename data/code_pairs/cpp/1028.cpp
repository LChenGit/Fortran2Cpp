// PermanentArrays.hpp
#include <vector>
#include <string>

class PermanentArrays {
public:
    std::vector<int> labels;
    std::vector<double> xparam;
    std::vector<std::string> simbol;
};

// test_permanent_arrays.cpp
#include "PermanentArrays.hpp"
#include <iostream>

int main() {
    PermanentArrays pa;

    pa.labels = {1, 2, 3, 4, 5};
    pa.xparam = {1.0, 2.0, 3.0, 4.0, 5.0};
    pa.simbol = {"H   ", "He  "}; // Space padded to match Fortran's fixed length

    std::cout << "Labels: ";
    for (const auto& label : pa.labels) {
        std::cout << label << " ";
    }
    std::cout << std::endl;

    std::cout << "XParam: ";
    for (const auto& x : pa.xparam) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::cout << "Simbol: ";
    for (const auto& s : pa.simbol) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    return 0;
}