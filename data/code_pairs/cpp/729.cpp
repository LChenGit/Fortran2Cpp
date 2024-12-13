#include <iostream>
#include <cmath>

float sdsdot(int N, float sb, const float *sx, int strideX, const float *sy, int strideY) {
    double dtemp = static_cast<double>(sb);
    if (N <= 0) {
        return static_cast<float>(dtemp);
    }
    
    int ix = 0, iy = 0;
    
    for (int i = 0; i < N; ++i) {
        dtemp += static_cast<double>(sx[ix]) * static_cast<double>(sy[iy]);
        ix += strideX;
        iy += strideY;
    }
    
    return static_cast<float>(dtemp);
}

int main() {
    float sx[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float sy[] = {1.0, 1.0, 1.0, 1.0, 1.0};
    float sb;
    int N, strideX, strideY;
    float result;

    // Test 1 - Basic dot product
    N = 5;
    sb = 0.0;
    strideX = 1;
    strideY = 1;
    result = sdsdot(N, sb, sx, strideX, sy, strideY);
    std::cout << "Test 1 (Basic): Expected 15.0, Got " << result << std::endl;

    // Test 2 - With scaling factor
    sb = 2.0;
    result = sdsdot(N, sb, sx, strideX, sy, strideY);
    std::cout << "Test 2 (Scaling): Expected 17.0, Got " << result << std::endl;

    // Test 3 - With strides
    strideX = 2;
    strideY = 2;
    result = sdsdot(3, sb, sx, strideX, sy, strideY);  // Adjusted N for stride to avoid out-of-bounds
    std::cout << "Test 3 (Strides): Expected 11.0, Got " << result << std::endl;

    return 0;
}