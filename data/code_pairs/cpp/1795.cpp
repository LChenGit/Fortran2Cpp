#include <array>
#include <memory>
#include <iostream>

class s {
public:
    std::array<int, 3> n;
};

class t {
public:
    std::shared_ptr<s> m = std::make_shared<s>(); // Initialize directly
};

std::array<int, 3> a;

void u() {
    t b;
    b.m->n.fill(1); // Fill with 1s
    a.fill(2); // Fill with 2s
    
    // Add arrays element-wise
    for (size_t i = 0; i < a.size(); ++i) {
        a[i] = a[i] + b.m->n[i] + 1 + i; // 1 + i to mimic (/1,2,3/)
    }
}

void test_u() {
    // Act
    u();
    // Assert
    std::array<int, 3> expected = {4, 5, 6};

    std::cout << "Testing C++ implementation:" << std::endl;
    std::cout << "Array a: ";
    for (auto& val : a) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    bool passed = true;
    for (size_t i = 0; i < expected.size(); ++i) {
        if (a[i] != expected[i]) {
            passed = false;
            break;
        }
    }
    if (passed) {
        std::cout << "Test u passed." << std::endl;
    } else {
        std::cout << "Test u failed." << std::endl;
    }
}

int main() {
    test_u();
    return 0;
}