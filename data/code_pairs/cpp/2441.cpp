#ifndef MATHLIB_HPP
#define MATHLIB_HPP

#include <stdexcept>

namespace mathlib {

    int add(int lhs, int rhs) {
        return lhs + rhs;
    }

    int sub(int lhs, int rhs) {
        return lhs - rhs;
    }

    int mul(int lhs, int rhs) {
        return lhs * rhs;
    }

    int divide(int lhs, int rhs) {
        if (rhs == 0) {
            throw std::invalid_argument("Division by zero is undefined.");
        }
        return lhs / rhs;
    }

    int mod(int lhs, int rhs) {
        if (rhs == 0) {
            throw std::invalid_argument("Modulo by zero is undefined.");
        }
        return lhs % rhs;
    }
} // namespace mathlib

#endif // MATHLIB_HPP