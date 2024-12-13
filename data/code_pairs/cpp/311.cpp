#include <vector>
#include <limits>
#include <cmath> // For std::isnan

double findMax(const std::vector<double>& A) {
    if (A.empty()) return std::numeric_limits<double>::quiet_NaN(); // Handling empty array case
    double BIGA = A[0];
    for (size_t i = 1; i < A.size(); ++i) {
        if (BIGA < A[i]) {
            BIGA = A[i];
        }
    }
    return BIGA;
}