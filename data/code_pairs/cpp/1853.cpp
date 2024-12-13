#include <iostream>
#include <cassert>

int Juldy(int Imon, int Id, int Iy) {
    int ITD[] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    if (Iy < 1800 || Imon < 1 || Imon > 12) {
        return -999;
    }
    int JulDy = Id;
    if (Imon == 1) {
        return JulDy;
    }
    JulDy += ITD[Imon - 2];
    if (Imon >= 3 && Iy % 4 == 0 && (Iy % 400 == 0 || Iy % 100 != 0)) {
        JulDy += 1;
    }
    return JulDy;
}

int main() {
    // Test 1: Non-leap year February 28
    assert(Juldy(2, 28, 2021) == 59);
    std::cout << "Test 1 passed." << std::endl;

    // Test 2: Leap year February 29
    assert(Juldy(2, 29, 2020) == 60);
    std::cout << "Test 2 passed." << std::endl;

    // Test 3: Invalid month
    assert(Juldy(13, 10, 2020) == -999);
    std::cout << "Test 3 passed." << std::endl;

    // Test 4: Early year (before 1800)
    assert(Juldy(3, 15, 1700) == -999);
    std::cout << "Test 4 passed." << std::endl;

    // Test 5: End of year
    assert(Juldy(12, 31, 2020) == 366);
    std::cout << "Test 5 passed." << std::endl;

    return 0;
}