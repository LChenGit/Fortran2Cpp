#include <vector>
#include <numeric> // For std::accumulate

int avg(const std::vector<int>& a) {
    if (a.empty()) {
        return 0; // Return 0 for an empty vector
    }
    int sum = std::accumulate(a.begin(), a.end(), 0);
    return sum / a.size();
}