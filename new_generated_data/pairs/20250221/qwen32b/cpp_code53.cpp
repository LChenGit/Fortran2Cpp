#include <iostream>
#include <cmath>
#include <cassert>

class Vector4P {
private:
    float x, y, z;

public:
    Vector4P(float x = 0.0f, float y = 0.0f, float z = 0.0f)
        : x(x), y(y), z(z) {}

    Vector4P operator+(const Vector4P& other) const {
        return Vector4P(x + other.x, y + other.y, z + other.z);
    }

    float magnitude() const {
        return std::sqrt(x * x + y * y + z * z);
    }
};

int main() {
    Vector4P ex(1.0f, 0.0f, 0.0f);
    Vector4P ey(0.0f, 1.0f, 0.0f);
    Vector4P ez(0.0f, 0.0f, 1.0f);

    Vector4P pt = ex + ey + ez;
    float mag_pt = pt.magnitude();

    // Output the magnitude and the result of the comparison
    std::cout << "Magnitude of pt: " << mag_pt << std::endl;
    std::cout << "Is 4.0 > mag_pt? " << (4.0f > mag_pt) << std::endl;

    // Unit test to verify the condition
    assert(4.0f > mag_pt && "Test case failed: 4.0 is not greater than the magnitude of pt");

    return 0;
}