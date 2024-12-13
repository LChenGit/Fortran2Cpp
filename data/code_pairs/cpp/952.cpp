#include <omp.h>
#include <iostream>

int main() {
    int sum = 0;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= 4; ++i) {
        sum += i;
    }

    std::cout << "Sum: " << sum << std::endl;
    return 0;
}