#include <iostream>
#include <complex>
using namespace std;

void CLASCL2(int M, int N, float D[], complex<float> X[], int LDX);

int main() {
    const int M = 2, N = 3, LDX = 2;
    float D[M] = {2.0f, 0.5f};
    complex<float> X[LDX * N] = {
        complex<float>(1.0f, 0.0f), complex<float>(0.0f, 1.0f),
        complex<float>(2.0f, 2.0f), complex<float>(3.0f, -1.0f),
        complex<float>(4.0f, 4.0f), complex<float>(5.0f, -2.0f)
    };

    // Call the function
    CLASCL2(M, N, D, X, LDX);

    // Print the result
    for (int j = 0; j < N; ++j) {
        cout << "Column " << j + 1 << ":" << endl;
        for (int i = 0; i < M; ++i) {
            cout << X[i + j * LDX].real() << " " << X[i + j * LDX].imag() << endl;
        }
    }

    return 0;
}

void CLASCL2(int M, int N, float D[], complex<float> X[], int LDX) {
    for (int J = 0; J < N; ++J) {
        for (int I = 0; I < M; ++I) {
            X[I + J * LDX] *= D[I];
        }
    }
}