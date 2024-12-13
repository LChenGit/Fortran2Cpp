// descramble_matrix.cpp
#include <iostream>
#include <vector>

void descramble_matrix(std::vector<std::vector<double>>& mat, int na, const std::vector<int>& nfps, const std::vector<int>& ixshells, int nshells) {
    if (na <= 0) {
        return;
    }

    std::vector<int> nfps_orig(nshells, 0);
    std::vector<double> xa(na);
    std::vector<int> ixa(na);

    for (int i = 0; i < nshells; ++i) {
        nfps_orig[ixshells[i] - 1] = nfps[i];
    }

    int istart = 0;
    for (int i = 0; i < nshells; ++i) {
        int ishell = ixshells[i];

        int n = 0;
        for (int j = 0; j < ishell - 1; ++j) {
            n += nfps_orig[j];
        }

        for (int j = 0; j < nfps_orig[ishell - 1]; ++j) {
            ixa[istart] = n + j;
            ++istart;
        }
    }

    for (int j = 0; j < na; ++j) {
        for (int i = 0; i < na; ++i) {
            xa[i] = mat[i][j];
        }

        for (int i = 0; i < na; ++i) {
            mat[ixa[i]][j] = xa[i];
        }
    }

    for (int i = 0; i < na; ++i) {
        for (int j = 0; j < na; ++j) {
            xa[j] = mat[i][j];
        }

        for (int j = 0; j < na; ++j) {
            mat[i][ixa[j]] = xa[j];
        }
    }
}

int main() {
    int na = 4;
    int nshells = 2;
    std::vector<int> nfps = {2, 2};
    std::vector<int> ixshells = {1, 2};

    std::vector<std::vector<double>> mat = {
        {1.0, 2.0, 3.0, 4.0},
        {5.0, 6.0, 7.0, 8.0},
        {9.0, 10.0, 11.0, 12.0},
        {13.0, 14.0, 15.0, 16.0}
    };

    descramble_matrix(mat, na, nfps, ixshells, nshells);

    std::cout << "Matrix after descrambling:" << std::endl;
    for (const auto& row : mat) {
        for (const auto& val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}