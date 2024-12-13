// asyncwait.cpp
#include <vector>
#include <openacc.h>

int main() {
    const int N = 64;
    std::vector<float> a(N, 3.0f); // Initialize vector a with N elements of value 3.0
    std::vector<float> b(N, 0.0f); // Initialize vector b with N elements of value 0.0

    #pragma acc parallel loop
    for (int i = 0; i < N; ++i) {
        b[i] = a[i] * 2.0f;
    }

    acc_wait_async(N); // Wait on the asynchronous queue numbered N.

    return 0;
}