#include <iostream>
#include <array>

class Vec3 {
public:
    std::array<float, 3> coords;

    Vec3() : coords{0.0f, 0.0f, 0.0f} {}

    Vec3(float x, float y, float z) : coords{x, y, z} {}
};

int main() {
    Vec3 v1(1.0f, 2.0f, 3.0f);
    Vec3 v2(4.0f, 5.0f, 6.0f);

    // Test initialization
    if (v1.coords[0] != 1.0f || v1.coords[1] != 2.0f || v1.coords[2] != 3.0f) {
        std::cerr << "ERROR in v1 initialization" << std::endl;
    }

    // Test modifying and accessing coords
    v2.coords[0] = 7.0f;
    v2.coords[1] = 8.0f;
    v2.coords[2] = 9.0f;

    for (int i = 0; i < 3; ++i) {
        if (v2.coords[i] != static_cast<float>(i + 7)) {
            std::cerr << "ERROR in v2 modification" << std::endl;
        }
    }

    std::cout << "All tests passed for C++ version." << std::endl;

    return 0;
}