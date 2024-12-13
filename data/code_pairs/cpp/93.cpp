#include <iostream>
#include <cmath>

int main() {
    double pi, x, y;

    pi = acos(-1.0);
    x = cos(pi);
    y = pow(sqrt(exp(log(pi))), 2);

    std::cout << "pi = " << pi << std::endl;
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;

    return 0;
}