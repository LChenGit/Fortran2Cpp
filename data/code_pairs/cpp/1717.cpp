#include <iostream>

// Function declaration
void cp_corrected(double& cp, double& Tg1, double& Tg2, double& cp_cor);

int main() {
    double cp = 1.5;
    double Tg1 = 300.0;
    double Tg2 = 350.0;
    double cp_cor;

    // Call the function
    cp_corrected(cp, Tg1, Tg2, cp_cor);

    // Check the result
    if (cp_cor == cp) {
        std::cout << "Test passed: cp_cor equals cp." << std::endl;
    } else {
        std::cout << "Test failed: cp_cor does not equal cp." << std::endl;
    }

    return 0;
}

// Function definition
void cp_corrected(double& cp, double& Tg1, double& Tg2, double& cp_cor) {
    Tg1 = Tg1; // Redundant in C++ as well, included for direct translation
    Tg2 = Tg2; // Redundant in C++ as well, included for direct translation
    cp_cor = cp;
}