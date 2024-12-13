#include <iostream>
#include <vector>

double gsw_gibbs_ice(int nt, int np, double t, double p) {
    // Placeholder implementation - replace with the actual Gibbs function for ice
    return t + p * 0.01;
}

double gsw_chem_potential_water_ice(double t, double p) {
    return gsw_gibbs_ice(0, 0, t, p);
}

int main() {
    std::vector<double> testTemps = {273.15, 263.15, 253.15};
    std::vector<double> testPressures = {101325.0, 50000.0, 200000.0};

    for (double t : testTemps) {
        for (double p : testPressures) {
            double result = gsw_chem_potential_water_ice(t, p);
            std::cout << "T=" << t << " K, P=" << p << " Pa, Chemical Potential=" << result << std::endl;
        }
    }

    return 0;
}