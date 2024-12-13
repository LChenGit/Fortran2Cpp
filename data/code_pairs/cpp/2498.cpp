#include <iostream>
#include <array>

namespace servo_with_limits_data {

using Real = double;  // Assuming mk maps to double

int nblades;
int stepno;
int stuck_type;

Real omega0;
Real beta0;
Real vmax;
Real amax;
Real theta_min;
Real theta_max;
Real time_runaway;
Real time_stuck;
Real stuck_angle;

Real oldtime;
Real theta_ref;

std::array<std::array<Real, 3>, 2> yold;
std::array<std::array<Real, 3>, 2> ynew;

std::array<Real, 100> oldarray2;

Real timestep;

} // namespace servo_with_limits_data

int main() {
    using namespace servo_with_limits_data;

    // Initialize variables
    nblades = 4;
    omega0 = 1.5;
    yold[0][0] = 1.0;
    ynew[1][2] = 1.0;

    oldarray2[49] = 50.0; // Indexing in C++ starts from 0

    // Print variables to verify
    std::cout << "nblades = " << nblades << std::endl;
    std::cout << "omega0 = " << omega0 << std::endl;
    std::cout << "yold(1,1) = " << yold[0][0] << std::endl;
    std::cout << "ynew(2,3) = " << ynew[1][2] << std::endl;
    std::cout << "oldarray2(50) = " << oldarray2[49] << std::endl;

    return 0;
}