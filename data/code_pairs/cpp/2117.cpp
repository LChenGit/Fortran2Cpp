#include <iostream>
#include <iomanip>
#include <algorithm>

// Function declaration
void dmat_prt(const double* dmat, int m, int n, int ld);

int main() {
    const int m = 3, n = 3, ld = 3;
    double dmat[9];

    // Initialize the matrix with values
    for (int i = 0; i < 9; ++i) {
        dmat[i] = static_cast<double>(i + 1);
    }

    // Call the dmat_prt function
    dmat_prt(dmat, m, n, ld);

    return 0;
}

// Function definition
void dmat_prt(const double* dmat, int m, int n, int ld) {
    if (m == 0 || n == 0 || ld < m) {
        return;
    }

    int start = 0;
    int cols = n;

    while (cols != 0) {
        int doing = std::min(3, cols - 1);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j <= doing; ++j) {
                std::cout << std::fixed << std::setw(19) << std::setprecision(12)
                          << dmat[start + i + j * ld];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

        doing += 1;
        cols -= doing;
        start += (ld * doing);
    }
}