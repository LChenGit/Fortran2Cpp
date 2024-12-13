#include <iostream>

using real = double;

class GSW_Toolbox {
public:
    // Placeholder for the gsw_gibbs_ice function
    static real gsw_gibbs_ice(int n1, int n2, real t, real p) {
        // Dummy implementation for demonstration - replace with actual calculations
        return t * p * 0.01;
    }
};

real gsw_alpha_wrt_t_ice(real t, real p) {
    return GSW_Toolbox::gsw_gibbs_ice(1, 1, t, p) / GSW_Toolbox::gsw_gibbs_ice(0, 1, t, p);
}

int main() {
    // Test case 1
    real t = 263.15;  // Kelvin
    real p = 10.0;    // Decibars
    std::cout << "Test case 1: T=" << t << " P=" << p << " Alpha=" << gsw_alpha_wrt_t_ice(t, p) << std::endl;

    return 0;
}