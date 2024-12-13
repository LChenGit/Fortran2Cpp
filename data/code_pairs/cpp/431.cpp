// amod_bmod.hpp
#include <vector>

namespace amod {
    void asubr(std::vector<int>& b);
}

struct Data1 { int a, b, c; };
struct Data2 { int d, e, f; };
struct Data3 { int g, h, i; };

namespace bmod {
    extern Data1 data1;
    extern Data2 data2;
    extern Data3 data3;
    void initializeCommonBlocks();
}

// amod_bmod.cpp
#include "amod_bmod.hpp"

namespace amod {
    void asubr(std::vector<int>& b) {
        for (auto& elem : b) {
            elem *= 2;
        }
    }
}

Data1 bmod::data1;
Data2 bmod::data2;
Data3 bmod::data3;

void bmod::initializeCommonBlocks() {
    data1 = {1, 2, 3};
    data2 = {4, 5, 6};
    data3 = {7, 8, 9};
}

// test.cpp
#include <iostream>
#include "amod_bmod.hpp"

void testAmod() {
    std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8};
    amod::asubr(array);
    std::cout << "Testing amod: asubr" << std::endl;
    for (int i = 0; i < array.size(); ++i) {
        std::cout << "array[" << i << "] = " << array[i] << std::endl;
    }
}

void testBmod() {
    bmod::initializeCommonBlocks();
    std::cout << "Testing bmod: common blocks" << std::endl;
    std::cout << "a, b, c: " << bmod::data1.a << ", " << bmod::data1.b << ", " << bmod::data1.c << std::endl;
    std::cout << "d, e, f: " << bmod::data2.d << ", " << bmod::data2.e << ", " << bmod::data2.f << std::endl;
    std::cout << "g, h, i: " << bmod::data3.g << ", " << bmod::data3.h << ", " << bmod::data3.i << std::endl;
}

int main() {
    testAmod();
    testBmod();
    return 0;
}