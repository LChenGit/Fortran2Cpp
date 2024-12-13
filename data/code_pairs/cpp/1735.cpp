#ifndef LDAU_HP_HPP
#define LDAU_HP_HPP

#include <vector>
#include <numeric> // For std::accumulate

class ldaU_hp {
public:
    double sum_array(const std::vector<double>& arr) const {
        return std::accumulate(arr.begin(), arr.end(), 0.0);
    }
};

#endif // LDAU_HP_HPP