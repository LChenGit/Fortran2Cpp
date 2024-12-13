#include <iostream>
#include <vector>
#include <stdexcept>

class Foo {
public:
    std::vector<int> a;
    std::vector<int> b;
};

class Bar {
public:
    Foo foo; // Composition to access `a` and `b` from Foo

    void mysub(int n, const std::vector<float>& parray1) {
        if ((n == 1) && parray1.size() != 10) {
            std::cerr << "Error: Expected size 10 for n=1" << std::endl;
            exit(1);
        }
        if ((n == 2) && parray1.size() != 42) {
            std::cerr << "Error: Expected size 42 for n=2" << std::endl;
            exit(2);
        }
    }
};

int main() {
    Foo foo;
    Bar bar;
    foo.a = {1, 6};
    foo.b = {10, 47};

    // Prepare test arrays
    std::vector<float> temp1(10, 1.0f); // Initialize temp1 with 1.0
    std::vector<float> temp2(42, 2.0f); // Initialize temp2 with 2.0

    // Perform tests
    try {
        bar.mysub(1, temp1); // Should pass
        bar.mysub(2, temp2); // Should pass
    } catch(const std::exception& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    return 0;
}