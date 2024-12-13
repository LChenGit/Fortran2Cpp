#include <iostream>
#include <vector>
#include <cassert>

class MultiDimArray {
public:
    std::vector<float> data;
    int upper[5] = {10, 10, 10, 3, 4};
    int lower[5] = {1, 1, 1, 1, 1}; // Fortran is 1-based indexing, adjusted for comparison

    MultiDimArray() : data(10 * 10 * 10 * 3 * 4) {}

    void check(const int* upper, const int* lower) {
        for (int i = 0; i < 5; ++i) {
            assert(this->upper[i] == upper[i]);
            assert(this->lower[i] == lower[i]);
        }
        std::cout << "check function PASSED." << std::endl;
    }
};

int main() {
    MultiDimArray f;
    int varu[5] = {10, 10, 10, 3, 4};
    int varl[5] = {1, 1, 1, 1, 1}; // Adjusted for 1-based indexing comparison

    // Upper bounds check
    for (int i = 0; i < 5; ++i) {
        assert(f.upper[i] == varu[i]);
    }
    std::cout << "Upper bounds check PASSED." << std::endl;

    // Lower bounds check
    for (int i = 0; i < 5; ++i) {
        assert(f.lower[i] == varl[i]);
    }
    std::cout << "Lower bounds check PASSED." << std::endl;

    // Check function tests
    f.check(varu, varl);

    return 0;
}