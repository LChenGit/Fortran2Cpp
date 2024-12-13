#include <iostream>
#include <cmath>
#include <iomanip>

double SHConfidence(int l_conf, double r);

int main() {
    double test_values[3] = {0.1, 0.5, 0.9};
    int l_conf_values[3] = {2, 5, 10};

    for (int test_case = 0; test_case < 3; ++test_case) {
        double result = SHConfidence(l_conf_values[test_case], test_values[test_case]);
        std::cout << "l_conf = " << l_conf_values[test_case] << ", r = " << test_values[test_case] 
                  << ", Result = " << std::setprecision(10) << result << std::endl;
    }

    return 0;
}

double SHConfidence(int l_conf, double r) {
    double prod = 1.0;
    double SHConfidence = std::abs(r);

    for (int l = 2; l <= l_conf; ++l) {
        int i = l - 1;
        prod *= static_cast<double>(2*i - 1) / static_cast<double>(2*i);
        SHConfidence += prod * std::abs(r) * std::pow(1.0 - r*r, l-1);
    }

    return SHConfidence;
}