#include <vector>

// Function to be tested
int sum_array(const std::vector<int>& array) {
    int total = 0;
    for(int num : array) {
        total += num;
    }
    return total;
}