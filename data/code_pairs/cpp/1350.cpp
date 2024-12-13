#include <iostream>
#include <iomanip>
#include <complex>
#include <array>

void vector_p2_exp_1d(double xmin, double xmax, double alpha, std::array<std::complex<double>, 3>& vecP2Exp) {
    std::complex<double> ii(0.0, 1.0);
    double alpha_h = alpha * (xmax - xmin);
    std::complex<double> z_1 = exp(ii * alpha * xmin);
    std::complex<double> z_2 = exp(ii * alpha * xmax);
    double fact1;

    if (std::abs(alpha_h) > 1.0e-3) {
        vecP2Exp[0] = ii * (-4.0 + std::pow(alpha_h, 2) - 3.0 * alpha_h * ii) * z_1 + (alpha_h + 4.0 * ii) * z_2;
        vecP2Exp[1] = (alpha_h - 4.0 * ii) * z_1 - ii * (-4.0 + std::pow(alpha_h, 2) + 3.0 * alpha_h * ii) * z_2;
        vecP2Exp[2] = -4.0 * (2.0 * ii * (-z_1 + z_2) + alpha_h * (z_1 + z_2));
        fact1 = std::pow(alpha, 3) * std::pow(xmax - xmin, 2);
    } else {
        std::complex<double> z_3 = exp(ii * alpha * (xmax + xmin) / 2.0);
        vecP2Exp[0] = (20.0 + std::pow(alpha_h, 2)) * z_1;
        vecP2Exp[1] = (20.0 + std::pow(alpha_h, 2)) * z_2;
        vecP2Exp[2] = -2.0 * (-40.0 + std::pow(alpha_h, 2)) * z_3;
        fact1 = 120.0 / (xmax - xmin);
    }

    for (int i = 0; i < 3; ++i) {
        vecP2Exp[i] /= fact1;
    }
}

int main() {
    std::array<std::complex<double>, 3> vecP2Exp;
    vector_p2_exp_1d(0.0, 1.0, 2.0, vecP2Exp);

    for (size_t i = 0; i < 3; ++i) {
        std::cout << "vecP2Exp[" << i << "] = " << std::fixed << std::setprecision(4)
                  << vecP2Exp[i] << std::endl;
    }

    return 0;
}