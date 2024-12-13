#include <iostream>
#include <string>

class Foo {
public:
    Foo(int n) {
        a = std::string(id(n), ' ');
        std::cout << "Array length: " << a.length() << std::endl;
    }

    int id(int a) const {
        std::cout << "ID function called with: " << a << std::endl;
        return a;
    }

private:
    std::string a;
};

void testFoo() {
    int testValue = 5;
    std::cout << "Testing with n = " << testValue << std::endl;
    Foo foo(testValue);
}

int main() {
    testFoo();
    return 0;
}