#include <iostream>
#include <vector>

struct s6 {
    int i;
};

struct s7 {
    float r;
};

void test_logic() {
    s6 s6_instance{0};
    std::vector<s7> s7_instances{{1.0f}, {2.0f}, {3.0f}};

    if (s6_instance.i != 0) {
        std::cerr << "Test failed: s6.i" << std::endl;
        return;
    }

    if (s7_instances[0].r != 1.0f) {
        std::cerr << "Test failed: s7(1).r" << std::endl;
        return;
    }

    if (s7_instances[1].r != 2.0f) {
        std::cerr << "Test failed: s7(2).r" << std::endl;
        return;
    }

    std::cout << "All tests passed." << std::endl;
}

int main() {
    test_logic();
    return 0;
}