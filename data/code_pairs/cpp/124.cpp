// sum_j.cpp
#include <iostream>
#include <cstdint>

extern "C" void SUM_J(int64_t* dv_result, const int64_t* dv_array, int64_t dv_dim, const bool* dv_mask) {
    *dv_result = 0; // Initialize result to 0.
    for (int64_t i = 0; i < dv_dim; ++i) {
        if (dv_mask[i]) {
            *dv_result += dv_array[i];
        }
    }
}

// This is the test program.
int main() {
    int64_t result = 0;
    int64_t array[5] = {1, 2, 3, 4, 5};
    bool mask[5] = {true, false, true, false, true};

    SUM_J(&result, array, 5, mask);

    std::cout << "Sum of masked elements: " << result << std::endl;
    // Expected output: Sum of masked elements: 9
    return 0;
}