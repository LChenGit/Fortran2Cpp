#include <iostream>
#include <cmath>

bool SIDEP(double ANGLE) {
    const double EPS = 1.27;
    const double PI = atan2(0.0, -1.0);

    if ((ANGLE > (PI - EPS)) && (ANGLE < (PI + EPS))) {
        return true;
    } else {
        return false;
    }
}

int main() {
    double test_angles[] = {0.0, 3.141592653589793, 6.283185307179586};
    int test_size = sizeof(test_angles)/sizeof(test_angles[0]);

    for(int i = 0; i < test_size; ++i) {
        bool result = SIDEP(test_angles[i]);
        std::cout << "ANGLE = " << test_angles[i] << " RESULT = " << std::boolalpha << result << std::endl;
    }

    return 0;
}