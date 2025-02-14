#include <iostream>
#include <limits>
#include <cmath>

template<typename T>
bool areClose(const T& a, const T& b, const T& tolerance = std::numeric_limits<T>::epsilon()) {
    return std::abs(a - b) <= std::max(std::abs(a), std::abs(b)) * tolerance;
}

int main() {
    double x = 1.0;
    double y = 1.000001;
    
    bool is_close = areClose(x, y);
    
    if (is_close) {
        std::cout << "Numbers are close." << std::endl;
    } else {
        std::cout << "Numbers are not close." << std::endl;
    }
    
    return 0;
}