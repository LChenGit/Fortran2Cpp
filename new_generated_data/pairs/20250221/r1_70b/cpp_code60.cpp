#include <vector>
#include <cassert>
#include <cmath>

using namespace std;

bool hasCloseElements(const vector<double>& actual, double expected_value, double tolerance) {
    for (double val : actual) {
        if (fabs(val - expected_value) > tolerance) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<double> values = {5.0, 4.9, 5.1};
    assert(hasCloseElements(values, 5.0, 0.95));
    return 0;
}