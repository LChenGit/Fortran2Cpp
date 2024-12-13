#include <iostream>
#include <vector>

// Function to normalize Cartesian coordinates
void ERD__NORMALIZE_CARTESIAN(int M, int NXYZ, int L, const std::vector<double>& NORM, std::vector<std::vector<double>>& BATCH) {
    int N = 0;
    double SCALAR, XNORM;

    for (int X = L; X >= 0; --X) {
        XNORM = NORM[X];
        int YBEG = L - X;
        for (int Y = YBEG; Y >= 0; --Y) {
            int Z = YBEG - Y;
            SCALAR = XNORM * NORM[Y] * NORM[Z];

            N += 1;

            for (int I = 0; I < M; ++I) {
                BATCH[I][N-1] = SCALAR * BATCH[I][N-1];
            }
        }
    }
}

int main() {
    const int M = 3;
    const int NXYZ = 6;
    const int L = 2;

    // Initialize NORM array
    std::vector<double> NORM = {1.0, 2.0, 3.0};

    // Initialize BATCH array
    std::vector<std::vector<double>> BATCH(M, std::vector<double>(NXYZ, 1.0));

    // Call the function
    ERD__NORMALIZE_CARTESIAN(M, NXYZ, L, NORM, BATCH);

    // Print the results for verification
    std::cout << "BATCH after normalization:" << std::endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < NXYZ; ++j) {
            std::cout << BATCH[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}