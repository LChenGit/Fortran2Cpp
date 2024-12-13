// intrinsic_dim_test.cpp
#include <iostream>

// Function to mimic Fortran's dim intrinsic function
template<typename T>
T dim(T x, T y) {
    return (x > y) ? (x - y) : 0;
}

int intrinsic_dim_test() {
    int i, j;
    float r, s; // float is typically 4 bytes (32 bits), equivalent to real(kind=4)
    double p, q; // double is typically 8 bytes (64 bits), equivalent to real(kind=8)

    i = 1;
    j = 4;
    if (dim(i, j) != 0) return 1;
    if (dim(j, i) != 3) return 2;

    r = 1.0f; // Suffix 'f' for float literals
    s = 4.0f;
    if (dim(r, s) != 0.0f) return 3;
    if (dim(s, r) != 3.0f) return 4;

    p = 1.0; // double literals
    q = 4.0;
    if (dim(p, q) != 0.0) return 5;
    if (dim(q, p) != 3.0) return 6;

    return 0; // All tests passed
}

int main() {
    int error = intrinsic_dim_test();
    if (error == 0) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Test failed with error code: " << error << std::endl;
    }

    return error;
}