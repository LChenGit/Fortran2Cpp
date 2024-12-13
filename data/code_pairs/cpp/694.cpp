#include <iostream>
#include <iomanip>
#include <vector>
#include <complex>
#include <cmath>
#include <omp.h>

using namespace std;

void initialData(int Nx, int Ny, const vector<double>& x, const vector<double>& y,
                 vector<vector<complex<double>>>& u, vector<vector<complex<double>>>& uold) {
    u.resize(Nx, vector<complex<double>>(Ny));
    uold.resize(Nx, vector<complex<double>>(Ny));

    #pragma omp parallel for collapse(2)
    for (int j = 0; j < Ny; ++j) {
        for (int i = 0; i < Nx; ++i) {
            u[i][j] = 0.5 * exp(-1.0 * (x[i]*x[i] + y[j]*y[j])) * sin(10.0 * x[i] + 12.0 * y[j]);
            uold[i][j] = u[i][j]; // Copying the initialized values from u to uold
        }
    }
}