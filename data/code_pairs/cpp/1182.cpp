#include <iostream>

int isALeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

void testLeapYear(int year, int expected) {
    int result = isALeapYear(year);
    if (result == expected) {
        std::cout << "Test passed for year " << year << std::endl;
    } else {
        std::cout << "Test failed for year " << year << ": Expected " << expected << ", got " << result << std::endl;
    }
}

int main() {
    testLeapYear(2000, 1); // Expected: 1
    testLeapYear(1900, 0); // Expected: 0
    testLeapYear(2016, 1); // Expected: 1
    testLeapYear(2019, 0); // Expected: 0

    return 0;
}