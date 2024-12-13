#include <iostream>
#include <vector>
#include <numeric>
#include <cstdlib>

void check(bool condition) {
    if (!condition) {
        std::cerr << "Check failed, aborting.\n";
        std::abort();
    }
}

int main() {
    std::vector<int> arr(12);
    std::iota(arr.begin(), arr.end(), 1); // Similar to arr = (/ (i, i = 1, 12) /)

    // Direct reshaping is not available in C++, but we can simulate basem's access
    auto basem = [&arr](int i, int j) -> int& {
        return arr[i * 4 + j]; // Assuming a 3x4 matrix shape
    };

    // Simulating vec(2:5) => arr(1:12:2)
    std::vector<int*> vec(4);
    for (int i = 0; i < 4; ++i) {
        vec[i] = &arr[i * 2]; // Pointing to every second element, starting from 0
    }
    check(vec.size() == 4);
    check(*vec[0] == 1 && *vec[3] == 7);

    // Simulating mat(1:3, 1:2) => vec
    std::vector<std::vector<int*>> mat(3, std::vector<int*>(2));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            mat[i][j] = vec[i * 2 + j]; // Adjusted to simulate the effect of reshaping
        }
    }
    check(*mat[0][0] == 1 && *mat[2][1] == 11);

    // vec(1:12_1) => basem
    // Point vec back to all elements of arr, simulating flat basem
    vec.resize(12);
    for (int i = 0; i < 12; ++i) {
        vec[i] = &arr[i];
    }
    check(*vec[0] == 1 && *vec[4] == 5 && *vec[11] == 12);

    std::cout << "All tests passed successfully." << std::endl;
    return 0;
}