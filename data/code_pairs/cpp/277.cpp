#include <iostream>
#include <vector>
#include <omp.h>

void norm(const std::vector<std::vector<double>>& vel, std::vector<double>& velnorm, int nef) {
    if (velnorm.size() != 5) {
        velnorm.resize(5, 0.0);
    } else {
        std::fill(velnorm.begin(), velnorm.end(), 0.0);
    }

    #pragma omp parallel for default(none) shared(vel, velnorm, nef) collapse(2) reduction(+:velnorm[:5])
    for (int i = 0; i < nef; ++i) {
        for (int j = 0; j < 5; ++j) {
            #pragma omp atomic
            velnorm[j] += vel[i][j] * vel[i][j];
        }
    }
}

int main() {
    int nef = 2;
    std::vector<std::vector<double>> vel(nef, std::vector<double>(8, 0.0));
    std::vector<double> velnorm(5, 0.0);

    for (int i = 0; i < nef; ++i) {
        for (int j = 0; j < 5; ++j) {
            vel[i][j] = i + 1 + j * 0.1;
        }
    }

    norm(vel, velnorm, nef);

    std::cout << "velnorm results:" << std::endl;
    for (size_t i = 0; i < velnorm.size(); ++i) {
        std::cout << "velnorm[" << i << "] = " << velnorm[i] << std::endl;
    }

    return 0;
}