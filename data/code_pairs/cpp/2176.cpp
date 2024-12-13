#include <iostream>
#include <cassert>

union Equivalence {
    float A;
    float B;
};

void verify(float x, float y, float expected) {
    assert(x == expected && y == expected && "Test Failed");
    std::cout << "Test Passed: A = " << x << " B = " << y << " Expected = " << expected << std::endl;
}

int main() {
    Equivalence eq;

    eq.A = 0.0f; // Initialize A
    verify(eq.A, eq.B, 0.0f);

    eq.B = 5.0f; // Modify B, which also modifies A due to union
    verify(eq.A, eq.B, 5.0f);

    return 0;
}