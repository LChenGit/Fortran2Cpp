// main.cpp
#include <iostream>
#include <iomanip>
#include <random>

int main() {
    const int N = 7;
    float a[N][N], b[N][N];
    float threshold = 0.5;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            a[i][j] = dis(gen);
            if (a[i][j] > threshold) {
                b[i][j] = a[i][j];
            } else {
                b[i][j] = 0.0;
            }
        }
    }

    std::cout << "Matrix a:" << std::endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << std::setw(8) << std::fixed << std::setprecision(2) << a[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Matrix b after applying threshold:" << std::endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << std::setw(8) << std::fixed << std::setprecision(2) << b[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}