// Filename: foo.cpp
#include <omp.h>

void foo(int &r) {
    #pragma omp parallel for reduction(+:r)
    for (int i = 1; i <= 10; ++i) {
        r += 1;
    }
}