#include <iostream>
#include <complex>
#include <cmath>
#include <cassert>

std::complex<double> specific_abs_c8(const std::complex<double>& parm) {
    return std::abs(parm); // Note: This should return a real value, not a complex one.
}