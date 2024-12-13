#include <vector>

int main() {
    const int N = 256;
    std::vector<double> a(N, 0.0);

    #pragma acc parallel loop
    for (int i = 0; i < N; ++i) {
        a[i] = 3.14;
    }

    return 0;
}