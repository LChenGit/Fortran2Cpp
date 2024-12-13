#include <iostream>
#include <openacc.h>

namespace test {
    void oacc1(int &result) {
        const int n = 5;
        int a[n];
        result = 0;

        #pragma acc data copyin(a) copyout(result)
        #pragma acc parallel loop reduction(+:result)
        for(int i = 1; i <= n; ++i) {
            result += i;
        }
    }
}