#include <iostream>
#include <cassert> // For assert

void v7swp(int n, float* x, float* y) {
    float t;
    for (int i = 0; i < n; i++) {
        t = x[i];
        x[i] = y[i];
        y[i] = t;
    }
}

void testSwap() {
    int n = 5;
    float x[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float y[] = {5.0, 4.0, 3.0, 2.0, 1.0};
    float expectedX[] = {5.0, 4.0, 3.0, 2.0, 1.0};
    float expectedY[] = {1.0, 2.0, 3.0, 4.0, 5.0};

    v7swp(n, x, y);

    for (int i = 0; i < n; i++) {
        assert(x[i] == expectedX[i] && "X array did not match expected values after swap.");
        assert(y[i] == expectedY[i] && "Y array did not match expected values after swap.");
    }

    std::cout << "Test passed: Arrays swapped correctly." << std::endl;
}

int main() {
    testSwap();
    return 0;
}