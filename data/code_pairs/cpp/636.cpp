#include <array>

class rrsw_kg18 {
public:
    static constexpr float pi = 3.14159f;
    std::array<float, 5> array1; // C++ arrays are 0-indexed
    std::array<float, 3> array2;

    rrsw_kg18() : array1(), array2() {}

    void computeSomething() {
        array1[0] = pi; // Equivalent to array1(1) in Fortran
        array2[2] = 2.0f * pi; // Equivalent to array2(3) in Fortran
    }
};