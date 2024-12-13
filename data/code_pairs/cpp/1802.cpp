#include <cmath> // for trigonometric and absolute value functions
#include <iostream>
#include <iomanip> // for std::setprecision

void wtproj(double dlat, double dlon, double& uval, double& vval, double cslt) {
    double tval = std::acos(std::cos(dlat) * std::cos(0.5 * dlon));
    
    if (std::abs(tval) > 1e-6) {
        tval = std::sin(tval) / tval;
    } else {
        tval = 1.0;
    }
    
    uval = 2.0 * std::cos(dlat) * std::sin(0.5 * dlon) / tval;
    vval = std::sin(dlat) / tval;
    
    uval = 0.5 * (dlon * cslt + uval);
    vval = 0.5 * (dlat + vval);
}

int main() {
    double dlat = 0.5, dlon = 0.5, cslt = 1.0;
    double uval, vval;
    
    wtproj(dlat, dlon, uval, vval, cslt);
    
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "UVAL: " << uval << " VVAL: " << vval << std::endl;
    
    return 0;
}