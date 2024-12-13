// Filename: test.cpp
#include <iostream>
#include <vector>
#include <cstdlib> // For std::abort()
#include <algorithm> // For std::any_of

struct CommonBlock {
    std::vector<float>* p;
    float q;

    CommonBlock() : p(nullptr), q(0) {}
} common;

void test() {
    if (std::any_of(common.p->begin(), common.p->end(), [](float val) { return val != 1.0f && val != 2.0f; })
        || common.q != 42.0f) {
        std::abort();
    }
}

int main() {
    // Test case 1: Expected to pass
    std::vector<float> a1 = {1.0, 2.0};
    float b1 = 42.0;
    common.p = &a1;
    common.q = b1;
    test();
    std::cout << "Test case 1 passed." << std::endl;

    return 0;
}