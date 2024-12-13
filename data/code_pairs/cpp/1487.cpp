#include <iostream>
#include <cassert>

int calculateEvenFibSum(int maximum) {
    int first = 1, second = 1, tmp = 0;
    int sumx = 0;

    while (true) {
        tmp = first + second;

        if (tmp > maximum) {
            break;
        }

        if (tmp % 2 == 0) {
            sumx += tmp;
        }

        first = second;
        second = tmp;
    }

    return sumx;
}

void testCalculateEvenFibSum() {
    int expected_sum = 4613732; // Pre-calculated expected result
    int actual_sum = calculateEvenFibSum(4000000);

    assert(actual_sum == expected_sum);
    std::cout << "Test Passed" << std::endl;
}

int main() {
    testCalculateEvenFibSum();
    return 0;
}