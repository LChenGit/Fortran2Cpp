#ifndef SIN_WRAPPER_H
#define SIN_WRAPPER_H

#include <cmath>

// Function pointer type that matches the Fortran interface
using SinInterface = float (*)(float);

// Wrapper function to adapt std::sin (which takes and returns double) to our interface
float sinWrapper(float x) {
    return static_cast<float>(std::sin(static_cast<double>(x)));
}

// Function that returns a pointer to a function matching the SinInterface
SinInterface f() {
    return &sinWrapper;
}

#endif // SIN_WRAPPER_H