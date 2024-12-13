// ds2hms.cpp
#include <iostream>
#include <cmath>

void ds2hms(double secs, int &hh, int &mm, double &ss) {
    const double s2h = 1.0 / 3600.0;
    const double s2m = 1.0 / 60.0;

    double s = secs;
    int h = static_cast<int>(s * s2h);
    s -= 3600 * h;
    int m = static_cast<int>(s * s2m);
    s -= 60 * m;

    hh = h;
    mm = m;
    ss = s;
}

void test_ds2hms() {
    int hh, mm;
    double ss;

    // Test case 1
    ds2hms(3661.0, hh, mm, ss);
    std::cout << "Test case 1: " << std::endl;
    std::cout << "Expected: 1, 1, 1.0" << std::endl;
    std::cout << "Actual: " << hh << ", " << mm << ", " << ss << std::endl;
    std::cout << "------------------------" << std::endl;

    // Additional test cases as shown in the unit test examples...

}

int main() {
    test_ds2hms();
    return 0;
}