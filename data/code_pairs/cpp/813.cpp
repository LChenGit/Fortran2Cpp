#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

int main() {
    std::vector<float> x = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    std::vector<float> y(5);
    std::vector<float> z(4);

    for (int i = 0; i < 5; ++i) {
        y[i] = i + 1;
    }

    // Operations demonstrated in the program
    std::cout << "x: ";
    for (auto val : x) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "y: ";
    for (auto val : y) std::cout << val << " ";
    std::cout << std::endl;

    float sumAbsDiff = 0.0f;
    for (size_t i = 0; i < x.size(); ++i) {
        sumAbsDiff += std::abs(x[i] - y[i]);
    }
    std::cout << "Sum of abs(x - y): " << sumAbsDiff << std::endl;

    float sumSquares = 0.0f;
    for (const auto& val : x) {
        sumSquares += val * val;
    }
    std::cout << "Square root of sum of x^2: " << std::sqrt(sumSquares) << std::endl;

    std::cout << "Size of x: " << x.size() << std::endl;

    for (int i = 0; i < 4; ++i) {
        z[i] = y[i + 1] - x[i];
    }
    std::cout << "z: ";
    for (auto val : z) std::cout << val << " ";
    std::cout << std::endl;

    return 0;
}