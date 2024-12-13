#include <iostream>
#include <cstdint>
#include <cassert>

struct TypeParamInt {
    std::int64_t i;
};

void test_type_param_int() {
    TypeParamInt t;
    t.i = 42;

    // Test if the integer holds the correct value
    assert(t.i == 42 && "Test failed: t.i should be 42");

    std::cout << "All tests passed." << std::endl;
}

int main() {
    test_type_param_int();
    return 0;
}