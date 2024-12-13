#include <iostream>
#include <vector>
#include <cstdlib> // For std::abort

// Template function to mimic Fortran's merge for scalar values
template<typename T>
T merge(const T& t, const T& f, bool condition) {
    return condition ? t : f;
}

// Template function to mimic Fortran's merge for arrays (vectors in C++)
template<typename T>
std::vector<T> merge(const std::vector<T>& t, const std::vector<T>& f, const std::vector<bool>& condition) {
    std::vector<T> result(t.size());
    for (size_t i = 0; i < t.size(); ++i) {
        result[i] = condition[i] ? t[i] : f[i];
    }
    return result;
}

int main() {
    std::vector<int> a = {-1, 2, 3};
    std::vector<int> b;
    int i;

    i = 5;
    if (merge(-1, 1, i > 3) != -1) std::abort();
    i = 1;
    if (merge(-1, 1, i >= 3) != 1) std::abort();

    std::vector<bool> condition(a.size());
    for (size_t idx = 0; idx < a.size(); ++idx) {
        condition[idx] = a[idx] >= 0;
    }
    b = merge(a, std::vector<int>(a.size(), 0), condition);

    for (size_t idx = 0; idx < b.size(); ++idx) {
        if (b[idx] != std::vector<int>({0, 2, 3})[idx]) std::abort();
    }

    return 0;
}