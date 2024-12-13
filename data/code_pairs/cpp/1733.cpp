#include <iostream>
#include <complex>
#include <algorithm>
#include <vector>

// Define DP (Double Precision) as a type alias for double
using DP = double;
using std::vector;
using std::complex;

// Function prototypes
complex<DP> get_alpha_pv(const vector<vector<DP>>& et);

int main() {
    // Example initialization of et with some values
    const int nbnd = 5; // Number of bands, example value
    const int nks = 10; // Number of k-points, example value
    vector<vector<DP>> et(nbnd, vector<DP>(nks, 0.0));
    for (int ibnd = 0; ibnd < nbnd; ++ibnd) {
        for (int iks = 0; iks < nks; ++iks) {
            et[ibnd][iks] = static_cast<DP>(ibnd + iks); // Example data
        }
    }
    
    auto alpha_pv = get_alpha_pv(et);
    std::cout << "get_alpha_pv result: " << alpha_pv.real() << " + " << alpha_pv.imag() << "i" << std::endl;
    
    return 0;
}

complex<DP> get_alpha_pv(const vector<vector<DP>>& et) {
    DP emin = et[0][0];
    DP emax = et[0][0];
    for (const auto& row : et) {
        for (const auto& elem : row) {
            emin = std::min(emin, elem);
            emax = std::max(emax, elem);
        }
    }
    
    DP alpha_pv = 2.0 * (emax - emin);
    alpha_pv = std::max(alpha_pv, 1.0e-2);
    
    return complex<DP>(alpha_pv, 0.0);
}