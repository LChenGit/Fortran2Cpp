#include <iostream>
#include <cmath>

int CSJRAND(int N, int& IX, int& IY, int& IZ) {
    IX = (171 * IX) % 30269;
    IY = (172 * IY) % 30307;
    IZ = (170 * IZ) % 30323;
    
    float X = (static_cast<float>(IX) / 30269.0f) + 
              (static_cast<float>(IY) / 30307.0f) +
              (static_cast<float>(IZ) / 30323.0f);

    float U = X - std::floor(X);
    return static_cast<int>(N * U + 1.0f); // Adjusted as per the Fortran logic
}

int main() {
    int n = 10;
    int ix = 12345;
    int iy = 67890;
    int iz = 13579;

    int result = CSJRAND(n, ix, iy, iz);

    std::cout << "CSJRAND Result: " << result << std::endl;

    if (result >= 1 && result <= n) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }

    return 0;
}