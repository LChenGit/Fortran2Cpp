// db.cpp
#include <cmath>
#include <iostream>
#include <cassert>

float db(float x) {
    if (x > 1.259e-10) {
        return 10.0f * log10(x);
    } else {
        return -99.0f;
    }
}

void testDb() {
    // Test cases
    assert(db(1.259e-10) == -99.0f);

    assert(std::abs(db(1.0f) - 0.0f) < 1e-5);

    assert(std::abs(db(100.0f) - 20.0f) < 1e-5);

    std::cout << "All tests passed successfully." << std::endl;
}

int main() {
    testDb();
    return 0;
}