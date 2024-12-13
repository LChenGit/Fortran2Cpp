#include <iostream>
#include <iomanip>

void writemac(double** mac, int nev, int nevcomplex);

int main() {
    const int nev = 2;
    const int nevcomplex = 2;
    double** mac = new double*[nev];

    // Allocate and initialize the mac array with some test values
    for (int i = 0; i < nev; ++i) {
        mac[i] = new double[nevcomplex];
        for (int j = 0; j < nevcomplex; ++j) {
            mac[i][j] = i + j * 0.1; // Example values
        }
    }

    // Call the writemac function
    writemac(mac, nev, nevcomplex);

    // Clean up the dynamically allocated memory
    for (int i = 0; i < nev; ++i) {
        delete[] mac[i];
    }
    delete[] mac;

    return 0;
}

void writemac(double** mac, int nev, int nevcomplex) {
    std::cout << std::endl;
    std::cout << "Modal Assurance Criterion" << std::endl;
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(4);

    for (int i = 0; i < nev; i++) {
        for (int j = 0; j < nevcomplex; j++) {
            std::cout << std::setw(12) << mac[i][j];
        }
        std::cout << std::endl;
    }
}