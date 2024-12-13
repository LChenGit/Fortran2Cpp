#include <array>
#include <cmath>
#include <iostream>

void distance_point_line_2D(const std::array<double, 2>& P0, 
                            const std::array<double, 2>& P1_line, 
                            const std::array<double, 2>& P2_line, 
                            double& dis, 
                            std::array<double, 2>& normal) {
    double a, b, c;
    a = P2_line[1] - P1_line[1];
    b = -(P2_line[0] - P1_line[0]);
    c = -(a * P1_line[0] + b * P1_line[1]);
    normal[0] = a / sqrt(pow(a, 2) + pow(b, 2));
    normal[1] = b / sqrt(pow(a, 2) + pow(b, 2));
    dis = (a * P0[0] + b * P0[1] + c) / sqrt(pow(a, 2) + pow(b, 2));
}