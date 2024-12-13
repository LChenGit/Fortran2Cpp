#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int N = 100;
    const int LIMIT = 60;
    std::vector<int> a(N);

    // Initialize the vector a
    for (int i = 0; i < N; ++i) {
        a[i] = i + 1;
    }

    for (int j = 1; j <= N; ++j) {
        #pragma omp parallel for if(j < LIMIT)
        for (int i = 0; i < N; ++i) {
            a[i] += 1;
        }
    }

    // Verification step (Output for demonstration)
    std::cout << "a[0]=" << a[0] << ", a[" << N-1 << "]=" << a[N-1] << std::endl;

    return 0;
}