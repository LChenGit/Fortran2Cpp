#include <iostream>
#include <algorithm>
#include <cmath>

// Assuming these constants are defined globally in the program
const double rytoev = 13.605693009;
const double ef = 10.0;
const double degauss = 0.0;
const int nelec = 10;
const bool noncolin = false;

void compute_eref_band(const double* e, int nbnd, double& eref, bool& print_eref) {
    print_eref = false;
    eref = -1e20; // Using scientific notation similar to Fortran's
    if (degauss > 0.0) {
        eref = ef * rytoev;
        print_eref = true;
    } else {
        int nband_occ = std::round(nelec / 2.0);
        if (noncolin) nband_occ *= 2;
        for (int ibnd = 0; ibnd < nband_occ; ++ibnd) { // Note: 0-based indexing in C++
            eref = std::max(eref, e[ibnd]);
        }
    }
}

int main() {
    const int nbnd = 5;
    double e[nbnd] = {5.0, 10.0, 15.0, 20.0, 25.0};
    double eref;
    bool print_eref;

    compute_eref_band(e, nbnd, eref, print_eref);

    std::cout << "Computed eref: " << eref << std::endl;
    std::cout << "Should print eref: " << print_eref << std::endl;

    return 0;
}