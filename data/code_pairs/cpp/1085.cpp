#include <iostream>
#include <omp.h>

void foo(int &r);

int main() {
    int r = 0;
    foo(r);

    if (r == 11) {
        std::cout << "Test passed, r = " << r << std::endl;
    } else {
        std::cerr << "Test failed, r = " << r << std::endl;
        return 1; // Indicate error
    }

    return 0; // Success
}

void foo(int &r) {
    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp target teams distribute parallel for reduction(+:r)
            for (int i = 1; i <= 10; ++i) {
                r = r + 1;
            }
            r = r + 1;
        }
    }
}