// main_subr.cpp
#include <array>

void subr(std::array<float, 50>& a) {
    for (auto& elem : a) {
        elem = 0;
    }
}