#include <cctype> // For std::isdigit and std::isalpha

void ST_ALNM(const char& chrstr, int& ityp, int& iret) {
    iret = 0; // Initialize iret to 0
    ityp = 0; // Initialize ityp to 0

    if (std::isdigit(static_cast<unsigned char>(chrstr))) {
        ityp = 1;
    } else if (std::isalpha(static_cast<unsigned char>(chrstr))) {
        ityp = 2;
    }
}