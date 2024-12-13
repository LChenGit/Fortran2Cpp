#include <vector>

// Forward declaration of the template function.
template<typename T>
int ice6_s(const T& a);

// Specialization for a vector (1D array).
template<typename T>
int ice6_s(const std::vector<T>& a) {
    return a.empty() ? -1 : 0;
}

// Overload for a vector of vectors (2D array).
template<typename T>
int ice6_s(const std::vector<std::vector<T>>& a) {
    return a.empty() ? -1 : ice6_s(a.front());
}