#include <iostream>
#include <omp.h>

int main() {
    int x = 2;

    #pragma omp task mergeable
    {
        x = x + 1;
    }

    #pragma omp taskwait

    std::cout << "x = " << x << std::endl;

    return 0;
}