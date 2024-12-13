#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

void avevar(const std::vector<double>& data, double& ave, double& var) {
    ave = 0.0;
    for (double d : data) {
        ave += d;
    }
    ave /= data.size();
    var = 0.0;
    double ep = 0.0;
    for (double d : data) {
        double s = d - ave;
        ep += s;
        var += s * s;
    }
    var = (var - ep * ep / data.size()) / (data.size() - 1);
}

void avevar2(const std::vector<double>& data, std::vector<double>& data2, double& ave, double& var) {
    avevar(data, ave, var);
    double std = sqrt(var);
    for (double d : data) {
        if (std::abs(d - ave) < 3.0 * std) {
            data2.push_back(d);
        }
    }
    if (!data2.empty()) {
        avevar(data2, ave, var);
    }
}

int main() {
    std::vector<double> data = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> data2;
    double ave, var;

    avevar(data, ave, var);
    std::cout << "Test avevar" << std::endl;
    std::cout << "Average: " << ave << std::endl;
    std::cout << "Variance: " << var << std::endl;

    avevar2(data, data2, ave, var);
    std::cout << "Test avevar2" << std::endl;
    std::cout << "Average: " << ave << std::endl;
    std::cout << "Variance: " << var << std::endl;
    std::cout << "Filtered Data (n <= 3*std): ";
    for (const auto& d : data2) {
        std::cout << d << " ";
    }
    std::cout << std::endl;

    return 0;
}