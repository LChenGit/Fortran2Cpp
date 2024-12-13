#include <iostream>
#include <cstdint>

extern "C" {
    void sub1(int32_t x) {
        std::cout << "sub1: " << x << std::endl;
    }

    void sub1_c(int32_t x) {
        std::cout << "sub1_c: " << x << std::endl;
    }

    void sub2_c(int32_t x) {
        std::cout << "sub2_c: " << x << std::endl;
    }

    void sub2(int32_t x) {
        std::cout << "sub2: " << x << std::endl;
    }

    void sub3_c(int32_t x) {
        std::cout << "sub3_c: " << x << std::endl;
    }

    void sub3_c_c(int32_t x) {
        std::cout << "sub3_c_c: " << x << std::endl;
    }
}

int main() {
    int32_t test_val = 123;

    sub1(test_val);
    sub1_c(test_val);
    sub2_c(test_val);
    sub2(test_val);
    sub3_c(test_val);
    sub3_c_c(test_val);

    return 0;
}