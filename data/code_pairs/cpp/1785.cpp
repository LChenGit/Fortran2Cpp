#include <iostream>
#include <vector>
#include <numeric>

int main() {
    int n = 3;
    std::vector<float> a(n, 3.0);
    float s = std::accumulate(a.begin(), a.end(), 0.0f);

    if (s != 9) {
        std::cerr << "Aborting due to unexpected sum." << std::endl;
        return 1;
    }

    // The test is implicitly passed if this point is reached.
    std::cout << "Test passed." << std::endl;

    return 0;
}