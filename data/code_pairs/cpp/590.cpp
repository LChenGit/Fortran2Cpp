#include <iostream>
#include <stdexcept>

struct t {
    int x;
};

class Incrementer {
public:
    static void increment(t& x) {
        for (int i = 1; i <= 1000; ++i) {
            x.x += 1;
        }
    }
};

int main() {
    t x{0}; // Initialize x.x to 0
    Incrementer::increment(x);
    if (x.x == 1000) {
        std::cout << "Test passed: Value is " << x.x << std::endl;
    } else {
        std::cerr << "Test failed: Expected 1000, got " << x.x << std::endl;
        return 1;
    }
    return 0;
}