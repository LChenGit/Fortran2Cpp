#include <iostream>
#include <array>

void testArray(const std::array<int, 5>& P) {
    for (size_t i = 0; i < P.size(); ++i) {
        if (P[i] != static_cast<int>((i + 1) * (i + 1))) {
            std::cerr << "Test failed at index: " << i << " Expected: " << (i + 1) * (i + 1) << " Got: " << P[i] << std::endl;
            return;
        }
    }
    std::cout << "All tests passed." << std::endl;
}

int main() {
    std::array<int, 5> P;

    for (int i = 0; i < 5; ++i) {
        P[i] = (i + 1) * (i + 1);
    }

    testArray(P);

    return 0;
}