#include <iostream>
#include <openacc.h>

// The function to be tested
extern "C" void oacc1(int& result) {
    const int n = 5;
    int a = 1;
    result = 0;

    #pragma acc parallel loop reduction(+:result)
    for (int i = 1; i <= n; i++) {
        result += a;
    }
}

int main() {
    int result;
    oacc1(result);
    std::cout << "Test passed: Result is " << result << std::endl;
    return 0;
}