#include <array>
#include <algorithm>

const int imax = 3;

int main() {
    std::array<float, imax+1> a{}; // C++ arrays are 0-indexed, size is imax+1 to include 0:imax range
    std::array<float, imax+1> b{};

    // Initialize b with some test data
    for(int i = 0; i <= imax; ++i) {
        b[i] = static_cast<float>(i);
    }

    // Copying elements from array b to array a
    std::copy(b.begin(), b.end(), a.begin());

    return 0;
}