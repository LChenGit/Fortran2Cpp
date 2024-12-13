// TT.hpp
#include <vector>
#include <algorithm>
#include <cmath>

class TT {
public:
    static std::vector<float> two(const std::vector<int>& N);
    static std::vector<float> twopointfive(const std::vector<int>& N);
};

// TT.cpp
#include "TT.hpp"

std::vector<float> TT::two(const std::vector<int>& N) {
    std::vector<float> result(N.size());
    std::transform(N.begin(), N.end(), result.begin(), [](int n) {
        return static_cast<float>(n) * 2.0f;
    });
    return result;
}

std::vector<float> TT::twopointfive(const std::vector<int>& N) {
    std::vector<float> result(N.size());
    std::transform(N.begin(), N.end(), result.begin(), [](int n) {
        return static_cast<float>(n) * 2.5f;
    });
    return result;
}