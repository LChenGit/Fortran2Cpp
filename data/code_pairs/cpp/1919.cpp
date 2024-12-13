#include <iostream>
#include <cstdlib> // For std::abort()

class DBaseSparseMat {
public:
    int v[10] = {0}; // Initialize all elements to 0

    DBaseSparseMat() = default;
    virtual ~DBaseSparseMat() = default;

    virtual void checkSize() const {
        if (sizeof(v) / sizeof(v[0]) != 10) {
            std::abort();
        }
        std::cout << "NV = " << sizeof(v) / sizeof(v[0]) << std::endl;
    }
};

int main() {
    DBaseSparseMat mat;
    mat.checkSize(); // Perform the check
    return 0;
}