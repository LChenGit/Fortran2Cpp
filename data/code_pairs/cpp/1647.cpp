// dswap.cpp
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

void dswap(int N, double* dx, int strideX, double* dy, int strideY) {
    if (N <= 0) {
        return;
    }

    int ix = 0;
    int iy = 0;

    for (int i = 0; i < N; ++i) {
        std::swap(dx[ix], dy[iy]);
        ix += strideX;
        iy += strideY;
    }
}

int main() {
    // Test case with N=3, stride=1 (optimized path)
    std::vector<double> dx = {1, 2, 3};
    std::vector<double> dy = {4, 5, 6};
    dswap(3, dx.data(), 1, dy.data(), 1);
    assert(dx == std::vector<double>({4, 5, 6}) && dy == std::vector<double>({1, 2, 3}));
    
    std::cout << "C++ code: All tests passed." << std::endl;
    return 0;
}