#include <vector>

void hunt(const std::vector<double>& xx, int n, double x, int& jlo) {
    bool ascnd = xx[n-1] > xx[0]; // Adjusted for 0-based indexing
    int jhi, jm;
    int inc = 1;

    jlo = (jlo <= 0 || jlo > n) ? 0 : jlo; // Adjust for 0-based indexing

    if ((x >= xx[jlo]) == ascnd) { // Adjust for 0-based indexing
        do {
            jhi = jlo + inc;
            if (jhi >= n) { // Adjust for 0-based indexing
                jhi = n;
                break;
            } else if ((x < xx[jhi]) == ascnd) {
                break;
            } else {
                jlo = jhi;
                inc *= 2;
            }
        } while (true);
    } else {
        do {
            jhi = jlo;
            jlo = jhi - inc;
            if (jlo < 0) { // Adjust for 0-based indexing
                jlo = 0;
                break;
            } else if ((x >= xx[jlo]) == ascnd) {
                break;
            } else {
                jhi = jlo;
                inc *= 2;
            }
        } while (true);
    }

    do {
        jm = (jhi + jlo) / 2;
        if ((x >= xx[jm]) == ascnd) {
            jlo = jm;
        } else {
            jhi = jm;
        }
    } while (jhi - jlo > 1);

    // No adjustment for jlo at the end, since we want the behavior matching Fortran
}