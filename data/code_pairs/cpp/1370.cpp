#include <iostream>
#include <memory>

class T {
    int value;  // Private integer value
public:
    T() : value(0) {}  // Default constructor initializes value to 0

    void setValue(int val) {
        value = val;
    }

    int getValue() const {
        return value;
    }
};

int main() {
    std::unique_ptr<T> var = std::make_unique<T>();

    // Test
    var->setValue(10);
    std::cout << var->getValue() << std::endl;  // Expected output: 10

    return 0;
}