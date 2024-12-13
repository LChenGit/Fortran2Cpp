#include <iostream>
#include <limits>
#include <cassert>

int main() {
    int i;
    double d = 2.0;
    double x = 1.0;
    double x_p;
    double calculated_epsilon;

    for (i = 1; i <= 2000; ++i) {
        x_p = x + d;
        if (x_p == x) {
            break;
        }
        d = d / 2.0;
    }
    
    calculated_epsilon = d * 2.0;

    // Test that calculated epsilon matches the std::numeric_limits epsilon
    assert(calculated_epsilon == std::numeric_limits<double>::epsilon());

    // Optionally, you can also print the results for verification
    std::cout << "Epsilon test passed." << std::endl;
    std::cout << "Iterations: " << i << " Calculated Epsilon: " << calculated_epsilon << std::endl;

    return 0;
}