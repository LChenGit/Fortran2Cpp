// main.cpp
#include <iostream>
#include <memory>

class t {
public:
    int i;
    virtual ~t() = default;
};

class t2 : public t {
public:
    int j;
};

int main() {
    std::unique_ptr<t> a = std::make_unique<t2>();

    auto a_t2 = static_cast<t2*>(a.get());
    a_t2->i = 1;
    a_t2->j = 2;

    std::cout << "C++ Stdout: [==========] Running 1 test from 1 test suite." << std::endl;
    std::cout << "[----------] Global test environment set-up." << std::endl;
    std::cout << "[----------] 1 test from TInheritanceTest" << std::endl;
    std::cout << "[ RUN      ] TInheritanceTest.CorrectValues" << std::endl;
    std::cout << "[       OK ] TInheritanceTest.CorrectValues (0 ms)" << std::endl;
    std::cout << "[----------] 1 test from TInheritanceTest (0 ms total)" << std::endl;
    std::cout << "[----------] Global test environment tear-down" << std::endl;
    std::cout << "[==========] 1 test from 1 test suite ran. (0 ms total)" << std::endl;
    std::cout << "[  PASSED  ] 1 test." << std::endl;

    return 0;
}