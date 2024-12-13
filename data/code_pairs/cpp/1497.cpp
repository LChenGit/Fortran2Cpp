#include <iostream>
#include <array>

std::array<int, 2> calculateNums() {
    std::array<int, 2> nums;
    for (int i = 0; i < 2; ++i) {
        nums[i] = i + 1 + 47; // Adjust for 0-based indexing
    }
    return nums;
}

int main() {
    auto nums = calculateNums();
    for (const auto& num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}