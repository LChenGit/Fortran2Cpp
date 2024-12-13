#include <array>

int main() {
    const int imax = 3;
    std::array<float, imax + 1> a{}; // +1 to account for 0-based indexing
    std::array<float, imax + 1> b{};

    // Initialize array b with some values
    for (int i = 0; i <= imax; ++i) {
        b[i] = i * 2.0f;
    }

    // Copy b into a
    a = b;

    // No explicit test is done here as the verification is done via the unit test below.
    return 0;
}