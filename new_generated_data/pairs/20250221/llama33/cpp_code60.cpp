#include <iostream>
#include <cmath>

int main() {
    const int nx = 100;
    const int ny = 100;

    // Initialize arrays
    double wrk[nx][ny];
    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny; ++j) {
            wrk[i][j] = static_cast<double>(i + j);
        }
    }

    double cf[6] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    double zf1[nx][ny];

    // Perform calculation
    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny - 5; ++j) {
            zf1[i][j] = wrk[i][j] * cf[0] + 
                        wrk[i][j + 1] * cf[1] + 
                        wrk[i][j + 2] * cf[2] + 
                        wrk[i][j + 3] * cf[3] + 
                        wrk[i][j + 4] * cf[4] + 
                        wrk[i][j + 5] * cf[5];
        }
    }

    // Print results
    std::cout << "C++ Results:" << std::endl;
    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny - 5; ++j) {
            std::cout << zf1[i][j] << std::endl;
        }
    }

    return 0;
}