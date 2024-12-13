#include <cassert>
#include <iostream>

class t {
public:
    bool x;

    t() : x(false) {}

    int onearg() const {
        return 5;
    }

    int twoarg1(int a) const {
        return 42;
    }

    int twoarg2(float a) const {
        return 123;
    }

    t& operator=(const bool& b) {
        x = !b;
        return *this;
    }
};

int main() {
    t obj;

    obj = false; // This should set obj.x to true
    assert(obj.x == true);
    std::cout << "Custom assignment operator test passed." << std::endl;

    assert(obj.onearg() == 5);
    std::cout << "onearg test passed." << std::endl;

    assert(obj.twoarg1(10) == 42);
    std::cout << "twoarg1 with int argument test passed." << std::endl;

    assert(obj.twoarg2(10.5f) == 123);
    std::cout << "twoarg2 with float argument test passed." << std::endl;

    std::cout << "All tests passed." << std::endl;

    return 0;
}