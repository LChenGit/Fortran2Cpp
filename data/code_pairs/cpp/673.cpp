#include <iostream>
#include <memory> // For std::unique_ptr
#include <cassert> // For assert()

class Foo {
public:
    Foo() : p(nullptr) {}

    int bar(int a) const {
        return a;
    }

private:
    std::unique_ptr<int> p;
};

void testBar() {
    Foo fooInstance;
    int result = fooInstance.bar(10);

    assert(result == 10); // Simple assertion to validate the result

    std::cout << "Test Passed: bar(10) = " << result << std::endl;
}

int main() {
    testBar(); // Run the test
    return 0;
}