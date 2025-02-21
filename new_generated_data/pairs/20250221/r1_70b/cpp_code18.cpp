#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

int main() {
    const int N = 1000;

    // Initialize A with ones and B with twos
    vector<vector<double>> A(N, vector<double>(N, 1.0));
    vector<vector<double>> B(N, vector<double>(N, 2.0));

    // Compute C = A + B
    vector<vector<double>> C(N, vector<double>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // Perform unit tests
    assert(C[0][0] == 3.0 && "Test case 1 failed: C[0][0] should be 3.0");
    assert(C[N/2][N/2] == 3.0 && "Test case 2 failed: C[N/2][N/2] should be 3.0");
    assert(C[N-1][N-1] == 3.0 && "Test case 3 failed: C[N-1][N-1] should be 3.0");

    cout << "All tests passed!" << endl;

    return 0;
}