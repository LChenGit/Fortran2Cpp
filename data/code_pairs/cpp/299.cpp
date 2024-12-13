#include <iostream>
#include <array>

struct g1 {
    std::array<int, 3> a;
    std::array<double, 3> r;
};

int main() {
    g1 ex, goal;

    // Initializing the entire arrays
    ex.a = {3, 0, 0};
    ex.r = {1.2, 0.0, 0.0};

    goal = ex;

    // Printing values (not a part of unit testing but for completeness)
    std::cout << "goal.a[0]: " << goal.a[0] << ", goal.r[0]: " << goal.r[0] << std::endl;

    return 0;
}