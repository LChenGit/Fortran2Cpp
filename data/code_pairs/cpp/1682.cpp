#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm> // For std::max_element

int main() {
    const int size = 1001;
    std::vector<double> x(size), y(size);
    
    for (int j = 0; j < size; ++j) {
        x[j] = -20.0 + j * 40.0 / 1000.0;
        if (x[j] == 0.0) {
            y[j] = 1.0;  // Handling the division by zero case
        } else {
            y[j] = sin(x[j]) / x[j];
        }
    }

    // Finding the maximum value in y
    auto max_iter = std::max_element(y.begin(), y.end());
    double max_value_of_y = *max_iter;
    
    std::cout << "The max value of y is " << max_value_of_y << std::endl;
    std::cout << "x[500] is " << x[500] << std::endl;  // C++ uses 0-based indexing
    std::cout << "y[500] is " << y[500] << std::endl;

    return 0;
}