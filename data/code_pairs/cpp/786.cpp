#include <iostream>
#include <cmath> // For fabs()

// Function prototype
void test(float x, float& y, float& z);

// A simple function to check the equality of floating-point numbers
bool areFloatsEqual(float a, float b, float epsilon = 0.001f) {
    return std::fabs(a - b) < epsilon;
}

int main() {
    float xx, yy, zz;

    xx = 10.0f;
    zz = 15.678f;

    test(xx, yy, zz);

    std::cout << "xx= " << xx << " yy= " << yy << " zz= " << zz << std::endl;

    // Unit test
    if (areFloatsEqual(yy, 190.0f) && areFloatsEqual(zz, 19.0f)) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }

    return 0;
}

void test(float x, float& y, float& z) {
    z = 19.0f;
    y = z * x;
}