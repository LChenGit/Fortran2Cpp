#include <iostream>
#include <string>

void mphys_tau_bin_interface() {
    // Single string for the message, to match Fortran output more closely
    std::string message = 
        "===========================================================\n"
        "This is a dummy stub for the Tel-Aviv University bin \n"
        "microphysics code. This code is not part of the current\n"
        "distribution.  To obtain the code, either email \n"
        "ben.shipway@metoffice.gov.uk or visit the downloads\n"
        "page at http://www.convection.info/microphysics\n"
        "The program will now exit...\n"
        "===========================================================";

    // Output the complete message
    std::cout << message << std::endl;

    // Exit the program
    exit(0);
}

int main() {
    // Call the function directly
    mphys_tau_bin_interface();
    return 0; // This line might not be reached due to the exit call in the function
}