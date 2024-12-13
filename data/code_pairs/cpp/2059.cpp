#include <iostream>
#include <vector>
#include <cassert>

int main() {
    std::vector<int> d(400, 0);
    d[0] = 1;
    int c = 0;
    int n = 1;

    for (int j = 0; j < 1000; ++j) {
        for (int i = 0; i < n; ++i) {
            d[i] = d[i] * 2 + c;
            c = 0;
            if (d[i] >= 10) {
                d[i] -= 10;
                c = 1;
            }
        }
        if (c > 0) {
            d[n] = c;
            ++n;
            c = 0;
        }
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += d[i];
    }

    // Known sum of digits for 2^1000
    int expected_sum = 1366;
    assert(sum == expected_sum && "Test Failed: Sum does not match the expected value.");

    std::cout << "Test Passed: Solution equals " << sum << std::endl;

    return 0;
}