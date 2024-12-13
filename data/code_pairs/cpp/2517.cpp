#include <iostream>
#include <vector>
#include <openacc.h>

int main() {
    std::vector<int> a(100);
    int j = 0;
    const int n = 100;

    #pragma acc parallel loop reduction(+:j)
    for (int i = 1; i <= n; ++i) {
        j = j + 1;
    }

    if (j != n) {
        std::cerr << "Test failed for C++ code: expected " << n << " but got " << j << std::endl;
        return 1;
    } else {
        std::cout << "Test passed for C++ code" << std::endl;
        return 0;
    }
}