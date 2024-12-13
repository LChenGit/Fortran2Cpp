#include <iostream>
#include <cstdint>
#include <cstring> // For memcpy

struct B8_COM {
    union {
        float B8_nfa;
        int32_t B8_cm;
    };
    static const int B8_sz = 1;
};

int main() {
    B8_COM b8;

    // Test modifying B8_nfa and reflecting on B8_cm
    b8.B8_nfa = 1.0f;
    std::cout << "After setting B8_nfa to 1.0, B8_cm is: " << b8.B8_cm << std::endl;

    // Test modifying B8_cm and reflecting on B8_nfa
    // Directly setting B8_cm with an int value that represents the float 2.0
    float two = 2.0f;
    memcpy(&b8.B8_cm, &two, sizeof(b8.B8_cm)); // Alternatively, assign directly if you know the exact int representation
    std::cout << "After setting B8_cm to represent 2.0, B8_nfa is: " << b8.B8_nfa << std::endl;

    return 0;
}