#include <vector>
#include <iostream>
#include <cassert>
#include <cmath>

void correct_flux(int n, const std::vector<double>& velocity, const std::vector<double>& area, 
                  const std::vector<double>& flux_in, std::vector<double>& flux_out, double correction) {
    for (int i = 0; i < n; ++i) {
        if (velocity[i] > 0.0) {
            flux_out[i] = flux_in[i] * area[i] * correction;
        } else {
            flux_out[i] = flux_in[i];
        }
    }
}

void test_correct_flux() {
    {
        std::vector<double> velocity = {0.0, -1.0, 0.0};
        std::vector<double> area = {1.0, 1.0, 1.0};
        std::vector<double> flux_in = {100.0, 200.0, 300.0};
        std::vector<double> flux_out(3);
        double correction = 1.5;

        correct_flux(3, velocity, area, flux_in, flux_out, correction);

        assert(flux_out[0] == 100.0 && flux_out[1] == 200.0 && flux_out[2] == 300.0);
    }

    {
        std::vector<double> velocity = {1.0, 2.0, 1.0};
        std::vector<double> area = {1.0, 1.0, 1.0};
        std::vector<double> flux_in = {100.0, 200.0, 300.0};
        std::vector<double> flux_out(3);
        double correction = 1.5;

        correct_flux(3, velocity, area, flux_in, flux_out, correction);

        assert(flux_out[0] == 150.0 && flux_out[1] == 300.0 && flux_out[2] == 450.0);
    }

    {
        std::vector<double> velocity = {0.0, 2.0, -1.0};
        std::vector<double> area = {1.0, 1.0, 1.0};
        std::vector<double> flux_in = {100.0, 200.0, 300.0};
        std::vector<double> flux_out(3);
        double correction = 1.5;

        correct_flux(3, velocity, area, flux_in, flux_out, correction);

        assert(flux_out[0] == 100.0 && flux_out[1] == 300.0 && std::fabs(flux_out[2] - 300.0) < 1e-5);
    }

    std::cout << "All tests passed." << std::endl;
}

int main() {
    test_correct_flux();
    return 0;
}