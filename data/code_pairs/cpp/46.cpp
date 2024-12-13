#include <iostream>
#include <cmath>

// Global variables
double XYTRAN_TRCOEFFS = 0.0;
double XYFIT_TRCOEFFS = 5.0;

// Function to perform the assignment
void perform_assignment() {
    XYTRAN_TRCOEFFS = XYFIT_TRCOEFFS;
}

// Main function for testing
int main() {
    // Run the assignment function
    perform_assignment();

    // Testing function
    if (std::fabs(XYTRAN_TRCOEFFS - XYFIT_TRCOEFFS) < 1e-6) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }

    return 0;
}