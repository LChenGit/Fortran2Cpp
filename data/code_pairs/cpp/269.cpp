#include <iostream>

void check_t_m(double& t_m) {
    if (t_m <= 0.0) {
        t_m = 1.0;
    }
}

int main() {
    double t_m = -1.0; // Example initialization; adapt as needed
    check_t_m(t_m);
    std::cout << "t_m: " << t_m << std::endl;
    return 0;
}