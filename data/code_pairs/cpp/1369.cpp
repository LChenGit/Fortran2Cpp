#include <vector>

class T1 {
public:
    int i;

    // Overload the assignment operator to mimic Fortran's generic assignment procedure.
    T1& operator=(const T1& rhs) {
        i = rhs.i;
        return *this;
    }
};

std::vector<T1> return_t1(const std::vector<T1>& arg) {
    return arg; // Direct copy of the argument vector.
}

std::vector<T1>& return_t1_p(std::vector<T1>& arg) {
    return arg; // Reference to mimic Fortran pointer behavior.
}