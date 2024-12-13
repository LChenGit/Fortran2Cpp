#include <vector>

void loop4_Cpp(int niters, int N, std::vector<double>& x, const std::vector<double>& a, const std::vector<double>& b) {
    for(int iter = 0; iter < niters; ++iter) {
        for(int i = 0; i < N; ++i) {
            x[i] = a[i] + b[i];
        }
    }
}