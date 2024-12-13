#include <iostream>
#include <omp.h>

bool test_parallel_sections() {
    const int size = 16;
    int* a = new int[size];

    for (int i = 0; i < size; ++i) {
        a[i] = 0;
    }

    #pragma omp parallel
    {
        #pragma omp sections reduction(+:a[:size])
        {
            #pragma omp section
            {
                for (int i = 0; i < size; ++i) {
                    a[i] = a[i] + 1;
                }
            }
            #pragma omp section
            {
                for (int i = 0; i < size; ++i) {
                    a[i] = a[i] + 2;
                }
            }
        }
    }

    bool valid = true;
    for (int i = 0; i < size; ++i) {
        if (a[i] != 3) {
            valid = false;
            break;
        }
    }

    delete[] a;
    return valid;
}

int main() {
    if (test_parallel_sections()) {
        std::cout << "Test Passed: All elements are 3." << std::endl;
    } else {
        std::cout << "Test Failed: Not all elements are 3." << std::endl;
        return 1;
    }
    return 0;
}