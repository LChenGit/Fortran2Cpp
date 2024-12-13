#include <iostream>

void LOADF(float* A, float* B, float* R, int N1, int N2, int N3, int N4, int N5) {
    for(int i = 0; i < N5; i++) {
        *(R + 0 * 2 * N5 + 0 * N5 + i) = *(B + 0 * N4 + i);
        *(R + 1 * 2 * N5 + 0 * N5 + i) = *(B + 1 * N4 + i);
        *(R + 2 * 2 * N5 + 0 * N5 + i) = *(B + 2 * N4 + i);
        
        *(R + 0 * 2 * N5 + 1 * N5 + i) = *(A + 0 * N2 + i);
        *(R + 1 * 2 * N5 + 1 * N5 + i) = *(A + 1 * N2 + i);
        *(R + 2 * 2 * N5 + 1 * N5 + i) = *(A + 2 * N2 + i);
    }
}

int main() {
    const int N1 = 3, N2 = 5, N3 = 3, N4 = 5, N5 = 5;
    float A[N1][N2], B[N3][N4], R[3][2][N5] = {{{0}}};

    // Initialize arrays A and B with some test values
    for(int i = 0; i < N1; i++) {
        for(int j = 0; j < N2; j++) {
            A[i][j] = i + j + 2; // +2 to match Fortran 1-indexing
        }
    }

    for(int i = 0; i < N3; i++) {
        for(int j = 0; j < N4; j++) {
            B[i][j] = i - j;
        }
    }

    // Call the LOADF function
    LOADF(&A[0][0], &B[0][0], &R[0][0][0], N1, N2, N3, N4, N5);

    // Print R array
    for(int k = 0; k < N5; k++) {
        std::cout << "R(:,:, " << k+1 << ")=" << std::endl;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 2; j++) {
                std::cout << R[i][j][k] << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}