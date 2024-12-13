#include <vector>

// Struct to hold shared variables
struct ComRp {
    static double ubar, vbar;
};

double ComRp::ubar = 0.0;
double ComRp::vbar = 0.0;

void rpn2cons_update(int meqn, int maux, int idir, int iface,
                     std::vector<double>& q,
                     const std::vector<double>& auxvec_center,
                     const std::vector<double>& auxvec_edge,
                     std::vector<double>& flux) {
    double urot = (idir == 0) ? ComRp::ubar : ComRp::vbar;

    for (int m = 0; m < meqn; ++m) {
        flux[m] = urot * q[m];
    }
}

void rpn2_cons_update_zero(int meqn, int maux, int idir, int iface,
                           const std::vector<double>& q,
                           const std::vector<double>& auxvec_center,
                           const std::vector<double>& auxvec_edge,
                           std::vector<double>& flux) {
    for (int m = 0; m < meqn; ++m) {
        flux[m] = 0.0;
    }
}