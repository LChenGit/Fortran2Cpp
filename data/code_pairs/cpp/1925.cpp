#include <vector>

int is_sorted_dble(const std::vector<double>& vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] < vec[i - 1]) {
            return i; // Adjusted for 0-based indexing
        }
    }
    return -1; // Indicates that the array is sorted
}