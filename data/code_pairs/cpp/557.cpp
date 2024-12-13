#include <vector>
#include <iostream>

void op(int n, const std::vector<double>& x, std::vector<double>& y, const std::vector<double>& ad, const std::vector<double>& au, const std::vector<int>& jq, const std::vector<int>& irow) {
    for (int i = 0; i < n; ++i) {
        y[i] = ad[i] * x[i];
    }
    for (int j = 0; j < n; ++j) {
        for (int l = jq[j] - 1; l < jq[j + 1] - 1; ++l) {
            int i = irow[l] - 1; // Adjusting for zero-based indexing
            y[i] += au[l] * x[j];
            y[j] += au[l] * x[i];
        }
    }
}