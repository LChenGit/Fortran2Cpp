#include <memory>
#include <iostream>

class A {
public:
    virtual ~A() = default;
    virtual void setValue(int val) = 0;
    virtual int getValue() const = 0;
};

class Derived : public A {
    int value;
public:
    void setValue(int val) override {
        value = val;
    }
    int getValue() const override {
        return value;
    }
};

class t {
public:
    std::shared_ptr<A> a;
    t() : a(std::make_shared<Derived>()) {} // Defaulting to Derived for demonstration
    void setValue(int val) {
        a->setValue(val);
    }
    int getValue() const {
        return a->getValue();
    }
};

int main() {
    t x;
    x.setValue(42);
    std::cout << "Value set in x, attempting to retrieve: " << x.getValue() << std::endl;
    t y = x; // Copy assignment
    std::cout << "Value in y after assignment from x: " << y.getValue() << std::endl;
}