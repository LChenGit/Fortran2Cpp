#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

class HaltonSequence {
public:
    static double get(int index, int base) {
        double result = 0.0, f = 1.0;
        int i = index;
        while (i > 0) {
            f = f / base;
            result = result + f * (i % base);
            i = i / base;
        }
        return result;
    }
};

void testHaltonSequence() {
    std::vector<double> expectedValues = {0.5, 0.25, 0.75, 0.125, 0.625};
    for (int n = 1; n <= expectedValues.size(); ++n) {
        double value = HaltonSequence::get(n, 2);
        assert(std::abs(value - expectedValues[n - 1]) < 1e-5);
    }
    std::cout << "All tests passed." << std::endl;
}

int main() {
    testHaltonSequence();
    return 0;
}