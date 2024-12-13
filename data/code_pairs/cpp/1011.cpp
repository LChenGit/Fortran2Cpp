#ifndef COSMOLOGY_PARAMETERS_H
#define COSMOLOGY_PARAMETERS_H

#include <string>

// Assuming the constants are defined in their respective namespaces
namespace constants {
    constexpr double pi = 3.14159265358979323846;
    constexpr double G_grav = 6.67430e-8; // in cgs units
    constexpr double Mpc = 3.085677581491367e24; // in cm
}

class cosmology_parameters {
public:
    static constexpr char cosmo_id[] = "WMAP5";
    static constexpr double h = 0.7;
    static constexpr double Omega0 = 0.279;
    static constexpr double Omega_B = 0.046;
    static constexpr double cmbtemp = 2.726;
    static constexpr double sigma8 = 0.817;
    static constexpr double n_s = 0.96;
    static constexpr double H0 = h * 100.0 * 1e5 / constants::Mpc;
    static constexpr double rho_crit_0 = 3.0 * H0 * H0 / (8.0 * constants::pi * constants::G_grav);
};

#endif // COSMOLOGY_PARAMETERS_H