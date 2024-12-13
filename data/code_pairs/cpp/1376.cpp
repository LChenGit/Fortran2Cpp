#include <cstdint>

extern "C" {
    int32_t myF90Int = 0;
    float myF90Real = 0.0f;
    int32_t c2 = 0; // Initialized as an example
    int32_t c3 = 0; // Initialized as an example
    int32_t c4 = 0; // Initialized as an example
    int32_t myF90Array3D[18][5][10] = {}; // Adjusted to match C++ indexing and dimensions
    int32_t myF90Array2D[3][2] = {}; // Initialized as an example
    
    void changeF90Globals() {
        myF90Int += 1;
        myF90Real *= 3.0f;
        c2 *= 2;
        c3 += 3;
        c4 /= 2;
        myF90Array3D[4][2][2] += 1; // Adjusted for 0-based indexing
        myF90Array2D[2][1] += 1;
    }
}