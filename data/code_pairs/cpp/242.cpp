#include <iostream>
#include <vector>
#include <omp.h>

void foo(std::vector<int>& a) {
    #pragma omp parallel for
    for(int i = 0; i < 30; ++i) {
        if ((i + 1) % 2 == 0) { // Fortran is 1-based index
            a[i] = 5;
        } else if (i + 1 <= 15) { // Adjusting condition to match Fortran's 1-based indexing
            a[i] = 2;
        } else {
            a[i] = 1;
        }
    }
}