#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

class T {
public:
    double expectedScalar;

    T() : expectedScalar(0.0) {}

    void FCheck(double x) {
        if (std::abs(x - expectedScalar) > 0.0001) {
            std::cerr << "Value does not match the expected scalar within tolerance." << std::endl;
            std::exit(1);
        }
    }

    void FCheckArr(const std::vector<double>& x) {
        for (int i = 0; i < x.size(); ++i) {
            expectedScalar = i;
            FCheck(x[i]);
        }
    }

    template<typename X>
    void Check(X x) {
        FCheck(x);
    }

    template<typename X>
    void Check(const std::vector<X>& x) {
        FCheckArr(x);
    }
};

int main() {
    T tester;
    tester.expectedScalar = 2.0;

    tester.Check(2.0);
    std::cout << "FCheck with single value passed." << std::endl;

    // Note: The Check with array is not demonstrated in the main function due to its exit behavior on mismatch,
    // but the capability is implemented in the class.
    return 0;
}