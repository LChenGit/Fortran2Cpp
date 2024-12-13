#include <iostream>
#include <vector>
#include <cmath>
#include <string>

void checksum(const std::string& sTag, const std::vector<double>& a) {
    double sm = 0.0;
    double nm = 0.0;

    for (double item : a) {
        sm += item;
        nm += item * item;
    }

    std::cout << "@CHECKSUM: " << sTag << " " 
              << std::scientific << sm << " " 
              << std::sqrt(nm) << std::endl;
}