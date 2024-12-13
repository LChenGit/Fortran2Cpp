#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>

void writematrix(const std::vector<double>& au, const std::vector<double>& ad, const std::vector<int>& irow, const std::vector<int>& jq, int neq, int number) {
    std::string name = "matrix_" + std::string(1, static_cast<char>('a' + number - 1)) + ".out";
    std::ofstream file(name);

    if (!file.is_open()) {
        std::cerr << "Failed to open file " << name << std::endl;
        return;
    }

    file << "matrix number " << number << std::endl;

    for (int i = 0; i < neq; ++i) {
        if (std::abs(ad[i]) > 1.e-20) {
            file << "row " << i + 1 << " value " << ad[i] << std::endl;
        }
    }

    for (int i = 0; i < neq; ++i) {
        int k = jq[i + 1] - jq[i];
        if (k > 0) file << "column " << i + 1 << std::endl;
        for (int j = jq[i]; j < jq[i + 1]; ++j) {
            file << "column " << i + 1 << " row " << irow[j - 1] << " value " << std::scientific << std::setprecision(8) << au[j - 1] << std::endl;
        }
    }
    file.close();
}

int main() {
    // Example usage
    std::vector<double> au = {0.5, 0.3, 0.6};
    std::vector<double> ad = {0.1, 0.2, 0.3};
    std::vector<int> irow = {1, 2, 3};
    std::vector<int> jq = {1, 2, 3, 4};
    int neq = 3;
    int number = 1;

    writematrix(au, ad, irow, jq, neq, number);

    return 0;
}