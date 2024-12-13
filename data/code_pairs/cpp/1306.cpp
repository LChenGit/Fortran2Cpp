#include <omp.h>
#include <iostream>

int main() {
    int sum = 0;
    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= 3; ++i) {
        sum += i;
    }
    std::cout << sum << std::endl;
    return 0;
}