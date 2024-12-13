#include <iostream>
#include <functional>

namespace m {
    using func_type = std::function<float(float)>;

    void sub(func_type a) {
        std::cout << a(4.0f) << std::endl;
    }
}

float foo(float x) {
    return x * 2.0f;
}

void testFoo() {
    float expected = 8.0f;
    float result = foo(4.0f);

    if (result == expected) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed. Expected " << expected << ", got " << result << std::endl;
    }
}

int main() {
    m::sub(foo);
    testFoo();
    return 0;
}