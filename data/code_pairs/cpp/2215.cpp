#include <iostream>
#include <iomanip> // For setprecision
#include <string>

// Define the external variables (mimicking global variables or constants)
double RAdate = 123.456;
double DECdate = 78.9;

// Define the external function smp_wrerr
void smp_wrerr(int s, const std::string& message) {
    std::cerr << "Error " << s << ": " << message << std::endl;
}

// Define the function enq_v2_path_comp
void enq_v2_path_comp(double& pc_ra, double& pc_dec, int s) {
    if (s != 0) return;

    pc_ra = RAdate;
    pc_dec = DECdate;

    if (s != 0) {
        smp_wrerr(s, "in subroutine enq_v2_path_comp.");
    }
}

int main() {
    double pc_ra = 0.0;
    double pc_dec = 0.0;
    int s = 0; // Or some other value to test the function

    // Call the function
    enq_v2_path_comp(pc_ra, pc_dec, s);

    // Print the results (for testing purposes), matching Fortran's default precision
    std::cout << std::fixed << std::setprecision(15); // Adjust precision to match Fortran output
    std::cout << "pc_ra: " << pc_ra << ", pc_dec: " << pc_dec << std::endl;

    return 0;
}