#include <iostream>
#include <functional>

// Define the functions f and g
double f() {
    return 1;
}

double g() {
    return 2;
}

// Define the subroutine s
void s() {
    std::function<double()> p;

    // Assign p to point to function g and call it
    p = g;
    std::cout << p() << std::endl;

    // Assign p to point to function f and call it
    p = f;
    std::cout << p() << std::endl;

    // Assign p back to g and call it again
    p = g;
    std::cout << p() << std::endl;
}

int main() {
    s();
    return 0;
}