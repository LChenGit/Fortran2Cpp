#include <iostream>
#include <cmath>

const double ZERO = 0.0;
const double PI = 3.14159265358979323846;
const double TWO_PI = 2.0 * PI;
const double TINYVAL = 1.0e-10;

void reduce(double& theta, double& phi) {
    if (std::abs(theta) < TINYVAL) theta += 0.0000001;
    if (std::abs(phi) < TINYVAL) phi += 0.0000001;

    double th = theta;
    double ph = phi;
    int i;

    // Adjust phi to be within [0, TWO_PI]
    if ((ph < ZERO) || (ph > TWO_PI)) {
        i = static_cast<int>(ph / TWO_PI);
        if (ph < ZERO) {
            ph += (std::abs(i) + 1) * TWO_PI;
        } else {
            ph -= std::abs(i) * TWO_PI;
        }
        phi = ph;
    }

    // Adjust theta to be within [0, PI]
    if ((th < ZERO) || (th > PI)) {
        i = static_cast<int>(th / PI);
        if (th > ZERO) {
            if (i % 2 != 0) {
                th = (i + 1) * PI - th;
                ph += PI;
            } else {
                th -= i * PI;
            }
        } else {
            th = -th;
            ph += PI;
        }
        if (ph >= TWO_PI) ph -= TWO_PI;
        theta = th;
        phi = ph;
    }
}

int main() {
    double theta, phi;

    // Test 1
    theta = -0.1; phi = TWO_PI + 0.1;
    reduce(theta, phi);
    std::cout << "Test 1 (Theta, Phi): " << theta << ", " << phi << std::endl;

    // Test 2
    theta = 3*PI/2; phi = -0.1;
    reduce(theta, phi);
    std::cout << "Test 2 (Theta, Phi): " << theta << ", " << phi << std::endl;

    // Add more tests as needed

    return 0;
}