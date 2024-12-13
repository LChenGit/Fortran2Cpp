#include <iostream>

class BrickTee {
private:
    double c, a, rho_te, sa, TE_0;
    double TE;

public:
    BrickTee() {}

    void init_brick_tee(double h_capacity, double expansion_coeff,
                        double density0, double ocsa, double Initial_TE,
                        double& thermal) {
        c = h_capacity;
        a = expansion_coeff;
        rho_te = density0;
        sa = ocsa;
        TE_0 = Initial_TE;

        thermal = TE_0;
        TE = thermal;
    }

    void brick_tee_step_forward(double deltaH, double thermal_previous,
                                 double& thermal_current) {
        thermal_current = thermal_previous + deltaH * a / (c * rho_te * rho_te * sa);
        TE = thermal_current;
    }

    void brick_tee_step_backward(double deltaH, double thermal_current,
                                 double& thermal_previous) {
        thermal_previous = thermal_current - deltaH * a / (c * rho_te * rho_te * sa);
    }
};