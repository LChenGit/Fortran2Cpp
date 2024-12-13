#include <iostream>
#include <vector>

void updat(std::vector<double>& u, std::vector<double>& udt, std::vector<double>& udtt, const std::vector<double>& ui, double a6, double a7, double a8, double a9, double a10) {
    size_t neq = u.size();

    for (size_t i = 0; i < neq; ++i) {
        u[i] += ui[i];
    }

    for (size_t i = 0; i < neq; ++i) {
        double udttld = udtt[i];
        udtt[i] = a6 * ui[i] + a7 * udt[i] + a8 * udttld;
        udt[i] += a9 * udttld + a10 * udtt[i];
    }
}