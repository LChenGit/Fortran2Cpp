// sum_array.cpp
#include <array>
#include <iostream>

int calculate_sum(const std::array<int, 5>& arr) {
    int sum = 0;
    for(int i = 0; i < arr.size(); ++i) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    std::cout << "Sum = " << calculate_sum(arr) << std::endl;
    return 0;
}