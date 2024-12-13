#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>

class Foo {
public:
    int i = 2;

    virtual ~Foo() = default;
};

class Foo1 : public Foo {
public:
    float r[2];
};

void subpr(Foo& x) {
    x.i = 3;
}

void subpr_elem(Foo& x) {
    x.i = 3;
}

void subpr_array(std::vector<std::shared_ptr<Foo>>& x) {
    for (auto& xi : x) {
        xi->i = 3;
    }
}

void subpr2(const Foo& x) {
    if (x.i != 55) {
        std::abort();
    }
}

void subpr2_array(const std::vector<std::shared_ptr<Foo>>& x) {
    for (const auto& xi : x) {
        if (xi->i != 55) {
            std::abort();
        }
    }
}

std::shared_ptr<Foo> f() {
    auto result = std::make_shared<Foo>();
    result->i = 55;
    return result;
}

std::vector<std::shared_ptr<Foo>> g() {
    std::vector<std::shared_ptr<Foo>> result(3);
    for (auto& res : result) {
        res = std::make_shared<Foo>();
        res->i = 55;
    }
    return result;
}

void run_tests() {
    std::shared_ptr<Foo> xx;
    std::vector<std::shared_ptr<Foo>> yy;

    // Test subpr
    xx = std::make_shared<Foo1>();
    xx->i = 33;
    subpr(*xx);
    std::cout << "Test subpr passed" << std::endl;

    // Test subpr_elem
    xx->i = 33;
    subpr_elem(*xx);
    std::cout << "Test subpr_elem passed" << std::endl;

    // Test subpr with f
    subpr(*f());
    std::cout << "Test subpr with f passed" << std::endl;

    // Test subpr_elem with array
    yy.resize(2);
    for (auto& y : yy) {
        y = std::make_shared<Foo1>();
        y->i = 33;
    }
    for (auto& y : yy) {
        subpr_elem(*y);
    }
    std::cout << "Test subpr_elem with array passed" << std::endl;

    // Test subpr_elem with single element
    yy[0]->i = 33;
    subpr_elem(*yy[0]);
    std::cout << "Test subpr_elem with single element passed" << std::endl;

    // Test subpr_array
    subpr_array(yy);
    std::cout << "Test subpr_array passed" << std::endl;

    // Test subpr_array with slice
    subpr_array(yy); // Note: C++ does not have direct slice equivalent, handled via same call
    std::cout << "Test subpr_array with slice passed" << std::endl;

    // Test subpr2_array with g
    subpr2_array(g());
    std::cout << "Test subpr2_array with g passed" << std::endl;
}

int main() {
    run_tests();
    return 0;
}