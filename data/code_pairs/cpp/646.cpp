#ifndef PPM_MODULE_FMM_TRAVERSE_HPP
#define PPM_MODULE_FMM_TRAVERSE_HPP

#include <iostream>

constexpr int SinglePrecision = 1;
constexpr int DoublePrecision = 2;
constexpr int SField = 9;
constexpr int VField = 10;

class PpmModuleFmmTraverse {
public:
    template<int Precision, int Field>
    static int traverse();
};

template<>
int PpmModuleFmmTraverse::traverse<SinglePrecision, SField>() {
    return 1;
}

template<>
int PpmModuleFmmTraverse::traverse<DoublePrecision, SField>() {
    return 2;
}

template<>
int PpmModuleFmmTraverse::traverse<SinglePrecision, VField>() {
    return 3;
}

template<>
int PpmModuleFmmTraverse::traverse<DoublePrecision, VField>() {
    return 4;
}

#endif