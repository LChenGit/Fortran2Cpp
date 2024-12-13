#include <vector>
#include <iostream>
#include <cstdlib> // For std::abort()

// Equivalent to Fortran's type t_1
struct t_1 {
    float coeff;
    t_1(float c = 99.0f) : coeff(c) {} // Constructor with default value matching Fortran's initialization
};

// Equivalent to Fortran's type t_2
struct t_2 {
    std::vector<t_1> mons;
    t_2(int size = 1, t_1 mon = t_1()) : mons(size, mon) {} // Constructor with default size and value
};

// Equivalent to Fortran's function a_fun
std::vector<t_2> a_fun(int r) {
    std::vector<t_2> p(r + 1, t_2()); // Create a vector of t_2 of size r+1
    return p;
}