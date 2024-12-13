#include <iostream>
#include <cstring> // For memcpy

union MixedType {
    int i;
    float r;
};

void A17_1_WRONG(MixedType& mix) {
    mix.i = 0; // Ensure a known starting state for consistency with Fortran example

    mix.i = mix.i + 1;

    // Use memcpy to avoid breaking strict aliasing rules
    float temp;
    memcpy(&temp, &mix.r, sizeof(float));
    temp = temp + 1.0f;
    memcpy(&mix.r, &temp, sizeof(float));

    std::cout << "After integer increment, I = " << mix.i << std::endl;
    // Perform a memcpy to safely read the float value due to strict aliasing rules
    memcpy(&temp, &mix.r, sizeof(float));
    std::cout << "After float increment, R = " << temp << std::endl;
}

int main() {
    MixedType mix;
    A17_1_WRONG(mix);
    return 0;
}