#include <cstdint>
#include <cfloat>
#include <iostream>
#include <cassert>

extern "C" {
    float myCFloat = 1.0f;
    int32_t myCInt = 42;
    int64_t myCInt2 = 84;
    float myCFloat2 = 3.0f;
    float myFloat = 4.0f;
    float myReal = 2.0f;
}

int main() {
    std::cout << "Testing C++ Variables" << std::endl;

    // Assertions to validate the initial values
    assert(myCFloat == 1.0f);
    assert(myCInt == 42);
    assert(myCInt2 == 84);
    assert(myCFloat2 == 3.0f);
    assert(myFloat == 4.0f);
    assert(myReal == 2.0f);
    
    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}