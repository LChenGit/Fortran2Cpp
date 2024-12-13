#include <array>
#include <iostream>

void iau_CP(const std::array<double, 3>& P, std::array<double, 3>& C) {
    for(int i = 0; i < 3; ++i) {
        C[i] = P[i];
    }
}

int main() {
    std::array<double, 3> P = {1.0, 2.0, 3.0};
    std::array<double, 3> C;

    iau_CP(P, C);

    for (int i = 0; i < 3; ++i) {
        std::cout << "C[" << i << "] = " << C[i] << std::endl;
    }

    return 0;
}