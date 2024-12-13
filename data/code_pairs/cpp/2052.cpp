#include <iostream>
#include <cassert>

class JulianDay {
public:
    static int julianDay(int yr, int mo, int da) {
        int a = (14 - mo) / 12;
        int y = yr + 4800 - a;
        int m = mo + 12 * a - 3;
        int julianDay = da + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
        return julianDay;
    }
};

void testJulianDay() {
    assert(JulianDay::julianDay(2000, 1, 1) == 2451545); // Test case 1
    
    std::cout << "All tests passed." << std::endl;
}

int main() {
    testJulianDay();
    return 0;
}