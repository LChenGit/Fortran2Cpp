#include <iostream>
#include <cmath>

class DE {
public:
    static float zu(float az, float xx) {
        return 1.0f - lz(az, xx) - lz(xx, az);
    }

    static float lz(float ho, float gh) {
        return std::sqrt(ho) - ho * gh;
    }
};

bool compareFloat(float a, float b, float tolerance = 0.0001f) {
    return std::abs(a - b) < tolerance;
}

int main() {
    float az = 4.0f, xx = 2.0f;

    float lzResult = DE::lz(az, xx);
    std::cout << "Test lz(4.0, 2.0): " << lzResult << std::endl;
    if (!compareFloat(lzResult, std::sqrt(az) - az * xx)) {
        std::cerr << "Test failed for lz(4.0, 2.0)" << std::endl;
    }

    float zuResult = DE::zu(az, xx);
    std::cout << "Test zu(4.0, 2.0): " << zuResult << std::endl;
    if (!compareFloat(zuResult, 1.0f - DE::lz(az, xx) - DE::lz(xx, az))) {
        std::cerr << "Test failed for zu(4.0, 2.0)" << std::endl;
    }

    return 0;
}