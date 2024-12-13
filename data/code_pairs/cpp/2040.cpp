#include <iostream>
#include <vector>
#include <algorithm>

int findMaxVal(const std::vector<int>& arr) {
    return *std::max_element(arr.begin(), arr.end());
}

int main() {
    std::vector<int> random_array = {100, 200, 300, 400, 500};
    int ans_val = findMaxVal(random_array);

    std::cout << "Maximum Value: " << ans_val << std::endl;

    return 0;
}