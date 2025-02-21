#include <cstdint>
#include <cstdlib>
#include <cassert>

void bar(uint8_t a, uint8_t b) {
    if (a != b) {
        exit(1);
    }
}

void foo(int8_t ii) {
    uint8_t b = ii;
    bar(static_cast<uint8_t>(ii), b);
}

int main() {
    int8_t ii = 7;
    
    // Unit test
    assert(static_cast<int8_t>(static_cast<uint8_t>(ii)) == ii);
    
    foo(ii);
    return 0;
}