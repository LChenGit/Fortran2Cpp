#include <iostream>
#include <cmath>
#include <string>

// Assuming these functions are defined elsewhere correctly.
double gsw_saar(double p, double lon, double lat) {
    // Dummy implementation for testing
    return 0.01;
}

double gsw_error_code(int code, const std::string &func_name) {
    // Dummy implementation for testing
    std::cerr << "Error in function " << func_name << ": code " << code << std::endl;
    return std::nan("");
}

double gsw_fdelta(double p, double lon, double lat) {
    const std::string func_name = "gsw_fdelta";
    const double gsw_error_limit = 0.02;
    double saar = gsw_saar(p, lon, lat);
    
    if (saar > gsw_error_limit) {
        return gsw_error_code(1, func_name);
    } else {
        return ((1.0 + 0.35) * saar) / (1.0 - 0.35 * saar);
    }
}

int main() {
    double result = gsw_fdelta(1000.0, 30.0, -60.0);
    std::cout << "gsw_fdelta(1000, 30, -60) = " << result << std::endl;
    return 0;
}