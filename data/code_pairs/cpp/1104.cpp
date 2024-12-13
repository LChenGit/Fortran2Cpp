#include <iostream>
#include <omp.h>

int parallel_sum(int n) {
    int var = 0;

    #pragma omp parallel for reduction(+:var)
    for(int i = 1; i <= n; ++i) {
        var += 1;
    }

    return var;
}

int main() {
    int n = 100;
    int result = parallel_sum(n);

    if(result != n) {
        std::cerr << "Error: The sum did not match the expected value." << std::endl;
        abort();
    }

    std::cout << "Test Passed: Sum is " << result << std::endl;
    return 0;
}