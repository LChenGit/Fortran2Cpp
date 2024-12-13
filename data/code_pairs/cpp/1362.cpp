#include <iostream>
#include <vector>

void clusfgt(int n, const std::vector<float>& x, int incx, float target, std::vector<std::vector<int>>& index, int& nclus) {
    nclus = 0;
    if (n < 1) return;
    int ib = 0; // Adjusted to 0-based indexing
    int nb = 0;
    
    for (int i = 0; i < n; ++i, ib += incx) {
        if (x[ib] > target) {
            if (nb == 0 || ib + 1 > index[1][nb-1]) { // Adjusted to 1-based indexing for output consistency
                index[0][nb] = ib + 1; // Adjust for 1-based indexing
                index[1][nb] = ib + 1;
                nb++;
            } else {
                index[1][nb-1] = ib + 1;
            }
        }
    }
    
    nclus = nb;
}

int main() {
    std::vector<std::vector<int>> index(2, std::vector<int>(100, 0)); // Adjust size as needed
    int nclus;
    std::vector<float> x = {0.7, 0.8, 0.9, 1.0, 1.1};
    int n = x.size(), incx = 1;
    float target = 0.6;

    clusfgt(n, x, incx, target, index, nclus);
    std::cout << "Test 1: Number of clusters: " << nclus << std::endl;

    // Add more tests as needed...

    return 0;
}