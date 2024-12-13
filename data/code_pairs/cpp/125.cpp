#include <vector>

void loop22_Cpp(int N, std::vector<double>& x, const std::vector<double>& a, const std::vector<double>& b, const std::vector<double>& c, const std::vector<double>& d) {
    for (int i = 0; i < N; ++i) {
        x[i] = x[i] + a[i] * b[i] + c[i] * d[i];
    }
}

void loop22_CppOverhead(int N, std::vector<double>& x, const std::vector<double>& a, const std::vector<double>& b, const std::vector<double>& c, const std::vector<double>& d) {
    // This function intentionally left blank, similar to the Fortran version.
}