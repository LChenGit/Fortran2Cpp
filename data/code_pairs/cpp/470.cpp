#include <iostream>
#include <vector>

// Global variables
const int Lsite = 5;
const double t0 = 1.0;
std::vector<std::vector<double>> Hmat_kin;

void PBME_allocation() {
    // Allocation and initialization
    Hmat_kin.resize(Lsite, std::vector<double>(Lsite, 0.0));

    for (int i = 0; i < Lsite; ++i) {
        int j = i + 1;
        if (j >= Lsite) j = 0; // Wrap around
        Hmat_kin[i][j] = -t0;

        j = i - 1;
        if (j < 0) j = Lsite - 1; // Wrap around
        Hmat_kin[i][j] = -t0;
    }
}

bool test_Hmat_kin_initialization() {
    PBME_allocation(); // Initializing the matrices and vectors

    // Test if Hmat_kin is initialized correctly
    for (size_t i = 0; i < Hmat_kin.size(); ++i) {
        if (Hmat_kin[i][(i + 1) % Lsite] != -t0 || Hmat_kin[i][(i - 1 + Lsite) % Lsite] != -t0) {
            return false;
        }
    }
    return true;
}

int main() {
    if (test_Hmat_kin_initialization()) {
        std::cout << "Hmat_kin allocation and initialization test passed." << std::endl;
    } else {
        std::cout << "Hmat_kin allocation and initialization test failed." << std::endl;
    }

    return 0;
}