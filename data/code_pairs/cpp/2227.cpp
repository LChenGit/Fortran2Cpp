#include <iostream>
#include <string>

namespace parameter {
    constexpr int lx = 128;
    constexpr int ly = 128;
    constexpr int lz = 128;
    constexpr int lstep = 10;
    constexpr int lnpx = 2;
    constexpr int lnpy = 2;
    constexpr int lnpz = 2;
    constexpr int llx = lx / lnpx;
    constexpr int lly = ly / lnpy;
    constexpr int llz = lz / lnpz;
}

void check_value(const std::string& name, int value, int expected) {
    if (value != expected) {
        std::cout << "Test failed for " << name << std::endl;
        std::cout << "Expected: " << expected << ", but got: " << value << std::endl;
    } else {
        std::cout << "Test passed for " << name << std::endl;
    }
}

int main() {
    check_value("lx", parameter::lx, 128);
    check_value("ly", parameter::ly, 128);
    check_value("lz", parameter::lz, 128);
    check_value("lstep", parameter::lstep, 10);
    check_value("lnpx", parameter::lnpx, 2);
    check_value("lnpy", parameter::lnpy, 2);
    check_value("lnpz", parameter::lnpz, 2);
    check_value("llx", parameter::llx, 64);
    check_value("lly", parameter::lly, 64);
    check_value("llz", parameter::llz, 64);

    return 0;
}