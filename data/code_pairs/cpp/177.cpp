#include <iostream>
#include <vector>

void s3(int n, std::vector<float>& z, const std::vector<float>& y) {
    z.resize(n);
    for (int i = 0; i < n; ++i) {
        z[i] = y[i];  // Copy operation
    }
}