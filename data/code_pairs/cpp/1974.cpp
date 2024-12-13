#include <iostream>
#include <vector>
#include <numeric>

// Function prototypes
std::vector<int> slice_and_subtract(const std::vector<int>& arr, int start, int end, int step, int subtract_value);
int f(const std::vector<int>& x);

int main() {
    std::vector<int> a = {1, 2, 3, 4, 5};
    int l = 4, u = 2;

    auto result = f(slice_and_subtract(a, l, u, -1, 2)); // Include step for reverse slicing
    std::cout << "Result in C++ program: " << result << std::endl;

    return 0;
}

// Function implementations
std::vector<int> slice_and_subtract(const std::vector<int>& arr, int start, int end, int step, int subtract_value) {
    std::vector<int> result;
    if (step > 0) {
        for (int i = start; i <= end; i += step) {
            result.push_back(arr[i - 1] - subtract_value); // 1-based to 0-based conversion
        }
    } else {
        for (int i = start; i >= end; i += step) {
            result.push_back(arr[i - 1] - subtract_value);
        }
    }
    return result;
}

int f(const std::vector<int>& x) {
    return std::accumulate(x.begin(), x.end(), 0);
}