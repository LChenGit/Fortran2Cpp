// ppm_module_tree_boxcut.h
#include <iostream>

template <typename Precision>
class PpmTreeBoxcut {
public:
    Precision operator()(Precision value) {
        return value * value; // Placeholder, actual implementation may vary
    }
};

// Specialization for float
template <>
class PpmTreeBoxcut<float> {
public:
    float operator()(float value) {
        std::cout << "Single Precision Implementation" << std::endl;
        return value * value;
    }
};

// Specialization for double
template <>
class PpmTreeBoxcut<double> {
public:
    double operator()(double value) {
        std::cout << "Double Precision Implementation" << std::endl;
        return value * value;
    }
};