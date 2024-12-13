#include <iostream>

// Assuming the existence of these functions based on the previous context.
extern "C" {
    double gsw_alpha_on_beta(double sa, double ct, double p);
    double gsw_rho(double sa, double ct, double p);
    void gsw_specvol_first_derivatives(double sa, double ct, double p, double& v_sa, double& v_ct);
    void gsw_specvol_second_derivatives(double sa, double ct, double p, double& v_sa_sa, double& v_sa_ct, double& v_ct_ct);
}

double gsw_cabbeling(double sa, double ct, double p) {
    double alpha_ct, alpha_on_beta, alpha_sa, beta_sa, rho;
    double v_sa, v_ct, v_sa_sa, v_sa_ct, v_ct_ct;

    gsw_specvol_first_derivatives(sa, ct, p, v_sa, v_ct);
    gsw_specvol_second_derivatives(sa, ct, p, v_sa_sa, v_sa_ct, v_ct_ct);

    rho = gsw_rho(sa, ct, p);

    alpha_ct = rho * (v_ct_ct - rho * v_ct * v_ct);
    alpha_sa = rho * (v_sa_ct - rho * v_sa * v_ct);
    beta_sa = -rho * (v_sa_sa - rho * v_sa * v_sa);

    alpha_on_beta = gsw_alpha_on_beta(sa, ct, p);

    return alpha_ct + alpha_on_beta * (2.0 * alpha_sa - alpha_on_beta * beta_sa);
}

int main() {
    double sa = 35.0;  // Practical Salinity, psu
    double ct = 10.0;  // Conservative Temperature, degrees C
    double p = 1000.0; // Pressure, dbar

    double cabbeling_coeff = gsw_cabbeling(sa, ct, p);

    std::cout << "Cabbeling coefficient: " << cabbeling_coeff << std::endl;

    return 0;
}