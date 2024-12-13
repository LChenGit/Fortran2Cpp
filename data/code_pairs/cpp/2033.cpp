// BoolArray.h
#include <iostream>

class BoolArray {
public:
    void subrBoolArrayIn(const bool* array_in, int n_in);
};

// BoolArray.cpp
#include "BoolArray.h"

void BoolArray::subrBoolArrayIn(const bool* array_in, int n_in) {
    std::cout << "SUBR_BOOLARRAY_IN" << std::endl;
    for (int i = 0; i < n_in; ++i) {
        std::cout << (i + 1) << " " << std::boolalpha << array_in[i] << std::endl;
    }
}