#include <iostream>
using namespace std;

void matrixTranspose(double** A, double** AT, int NR, int NC, int NTR, int NTC) {
    for (int i = 0; i < NTR; ++i) {
        for (int j = 0; j < NTC; ++j) {
            AT[j][i] = A[i][j];
        }
    }
}

void printMatrix(double** M, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example usage with a square matrix 3x3
    cout << "Square Matrix 3x3 Transpose:" << endl;
    double A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    double AT[3][3];
    double* Ap[3] = {A[0], A[1], A[2]};
    double* ATp[3] = {AT[0], AT[1], AT[2]};
    matrixTranspose(Ap, ATp, 3, 3, 3, 3);
    printMatrix(ATp, 3, 3);

    // Additional tests for non-square matrices, 1x1 matrix, and matrices with one row or column
    // should follow the implementation pattern demonstrated above.

    return 0;
}