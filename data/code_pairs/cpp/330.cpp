#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void matrix_multiply(const std::vector<std::vector<float>>& a, 
                     const std::vector<std::vector<float>>& b, 
                     std::vector<std::vector<float>>& c, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = 0.0f;
            for (int k = 0; k < n; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    const int n = 100; // Adjusted for testability
    vector<vector<float>> a(n, vector<float>(n, 1.0f));
    vector<vector<float>> b(n, vector<float>(n, 2.0f));
    vector<vector<float>> c(n, vector<float>(n, 0.0f));

    auto start = high_resolution_clock::now();

    matrix_multiply(a, b, c, n);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    double seconds = duration.count() / 1e6;

    double gflops = (double(n) * double(n) * double(n) * 2.0) / (seconds * 1e9);
    cout << "Total Time: " << seconds << " seconds" << endl;
    cout << "Total MM GFLOPS: " << gflops << endl;

    return 0;
}