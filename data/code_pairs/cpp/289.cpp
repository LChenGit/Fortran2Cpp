// initialdata.h
#include <vector>
#include <complex>
#include <cmath>

void initialdata(int Nx, int Ny, int Nz, const std::vector<double>& x, const std::vector<double>& y, const std::vector<double>& z, std::vector<std::vector<std::vector<std::complex<double>>>>& u, std::vector<std::vector<std::vector<std::complex<double>>>>& uold);

// initialdata.cpp
#include "initialdata.h"
#include <omp.h>

void initialdata(int Nx, int Ny, int Nz, const std::vector<double>& x, const std::vector<double>& y, const std::vector<double>& z, std::vector<std::vector<std::vector<std::complex<double>>>>& u, std::vector<std::vector<std::vector<std::complex<double>>>>& uold) {
    u.resize(Nx, std::vector<std::vector<std::complex<double>>>(Ny, std::vector<std::complex<double>>(Nz)));
    uold.resize(Nx, std::vector<std::vector<std::complex<double>>>(Ny, std::vector<std::complex<double>>(Nz)));

    #pragma omp parallel for collapse(3) schedule(static)
    for (int k = 0; k < Nz; ++k) {
        for (int j = 0; j < Ny; ++j) {
            for (int i = 0; i < Nx; ++i) {
                u[i][j][k] = std::complex<double>(0.5) * std::exp(-1.0 * (x[i] * x[i] + y[j] * y[j] + z[k] * z[k]));
                uold[i][j][k] = u[i][j][k];
            }
        }
    }
}

// test_initialdata.cpp
#include <gtest/gtest.h>
#include "initialdata.h"

TEST(InitialDataTest, TestEquality) {
    int Nx = 10, Ny = 10, Nz = 10;
    std::vector<double> x(Nx), y(Ny), z(Nz);
    for (int i = 0; i < Nx; ++i) {
        x[i] = (i + 1) / 10.0;
        y[i] = (i + 1) / 10.0;
        z[i] = (i + 1) / 10.0;
    }

    std::vector<std::vector<std::vector<std::complex<double>>>> u, uold;
    initialdata(Nx, Ny, Nz, x, y, z, u, uold);

    for (int k = 0; k < Nz; ++k) {
        for (int j = 0; j < Ny; ++j) {
            for (int i = 0; i < Nx; ++i) {
                EXPECT_EQ(u[i][j][k], uold[i][j][k]);
            }
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}