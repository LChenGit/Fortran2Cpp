#include <vector>
#include <iostream>

void clusigt(int n, const std::vector<int>& x, int incx, int target, std::vector<std::vector<int>>& index, int& nclus) {
    if (n < 1) {
        nclus = 0;
        return;
    }

    int ib, ie, nb, ne;
    if (incx >= 0) {
        ib = 0;
        ie = 0;
    } else {
        ib = 1 - incx * (n - 1) - 1;
        ie = 1 - incx * (n - 1) - 1;
    }

    nb = 0;
    for (int i = 0; i < n; ++i) {
        if (x[ib] > target) {
            if (i == 0 || x[ib - incx] <= target) {
                index[0][nb] = i + 1; // Adjusting for one-based indexing
                nb++;
            }
        }
        ib += incx;
    }

    ne = 0;
    if (nb > 0) {
        for (int i = 0; i < n - 1; ++i) {
            if (x[ie] > target && x[ie + incx] <= target) {
                index[1][ne] = i + 1; // Adjusting for one-based indexing
                ne++;
            }
            ie += incx;
        }
        if (x[ie] > target) {
            index[1][ne] = n;
            ne++;
        }
    }

    nclus = nb;
}

int main() {
    std::vector<int> x = {5, 6, 7, 8, 9, 10, 11};
    int n = x.size();
    std::vector<std::vector<int>> index(2, std::vector<int>(n, 0));
    int nclus;

    clusigt(n, x, 1, 9, index, nclus);

    std::cout << "nclus = " << nclus << std::endl;
    for (int i = 0; i < nclus; ++i) {
        std::cout << "Cluster " << i+1 << ": Start = " << index[0][i] << ", End = " << index[1][i] << std::endl;
    }

    return 0;
}