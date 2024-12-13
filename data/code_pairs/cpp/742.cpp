// clascl2.cpp
#include <iostream>
#include <complex>
#include <cassert>

using namespace std;

void clascl2(int m, int n, float* D, complex<float>* X, int ldx) {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            X[i + j*ldx] *= D[i];
        }
    }
}

int main() {
    const int M = 2, N = 3, LDX = 2;
    float D[M] = {2.0, 3.0};
    complex<float> X[LDX*N] = { {1.0,1.0}, {2.0,2.0}, {3.0,3.0},
                                {4.0,4.0}, {5.0,5.0}, {6.0,6.0} };

    clascl2(M, N, D, X, LDX);

    cout << "Scaled Matrix X:" << endl;
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < M; i++) {
            auto val = X[i + j*LDX];
            cout << "(" << val.real() << "," << val.imag() << ") ";
        }
        cout << endl;
    }

    // Example assertion to verify correctness
    assert(X[0] == complex<float>(2.0, 2.0)); // The first element should be (2,2) after scaling

    cout << "Test completed successfully." << endl;

    return 0;
}