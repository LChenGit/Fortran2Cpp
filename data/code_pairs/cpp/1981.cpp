#ifndef FOO_H
#define FOO_H

#include <complex>
#include <cstdint>

extern "C" {
    void foo(int32_t x, float y, std::complex<float> z, std::complex<float> a);
}

#endif // FOO_H