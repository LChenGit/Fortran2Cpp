#include <iostream>
#include <memory>

class Test {
public:
    int i;
    Test(int value) : i(value) {}
};

class TestReference {
public:
    std::shared_ptr<Test> test;
    TestReference(std::shared_ptr<Test> t) : test(t) {}
};

int main() {
    bool test_passed = true;

    std::shared_ptr<Test> x = std::make_shared<Test>(99);
    TestReference testList(x);

    std::shared_ptr<Test> y = testList.test;

    if (x->i != y->i) {
        std::cerr << "Test failed: x->i != y->i" << std::endl;
        test_passed = false;
    }

    if (y) {
        if (x->i != y->i) {
            std::cerr << "Test failed: x->i != y->i (inside check)" << std::endl;
            test_passed = false;
        }
    } else {
        std::cerr << "Test failed: Type mismatch" << std::endl;
        test_passed = false;
    }

    if (test_passed) {
        std::cout << "C++ Test Passed!" << std::endl;
    } else {
        std::cout << "C++ Test Failed!" << std::endl;
    }

    return 0;
}