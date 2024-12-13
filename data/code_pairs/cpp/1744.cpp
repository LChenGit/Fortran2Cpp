#include <iostream>
#include <complex>
#include <cstdint>
#include <vector>

int32_t IZAMAX(int32_t N, const std::complex<double>* ZX, int32_t INCX) {
    int32_t index = 0;
    double max_val = std::abs(ZX[0]);
    for (int32_t i = 1; i < N; i += INCX) {
        if (std::abs(ZX[i]) > max_val) {
            max_val = std::abs(ZX[i]);
            index = i;
        }
    }
    return index + 1; // Convert to 1-based index to match Fortran behavior
}

int main() {
    std::vector<std::complex<double>> arr = {
        {1, 2}, {2, 4}, {3, 6}, {4, 8}, {5, 10}
    };

    int32_t result = IZAMAX(arr.size(), arr.data(), 1);
    std::cout << "The index of max abs value is: " << result << std::endl;
    return 0;
}