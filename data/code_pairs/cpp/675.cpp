#include <vector>

// Translated loop8_F77 subroutine to C++
void loop8_F77(int N, std::vector<double>& a, std::vector<double>& x, double u) {
    for (int i = 0; i < N; ++i) {
        x[i] = u / a[i];
    }
}