#include <iostream>
#include <memory>

// Abstract base class
class t {
public:
    virtual void display() = 0; // Pure virtual function for polymorphic behavior
    virtual ~t() = default; // Virtual destructor for proper cleanup
};

// Derived class implementing the display method
class t_derived : public t {
public:
    void display() override {
        std::cout << "Display from derived class." << std::endl;
    }
};

// Test function demonstrating dynamic allocation and polymorphism
void test() {
    std::unique_ptr<t> obj = std::make_unique<t_derived>(); // Dynamic allocation of derived class
    obj->display(); // Polymorphic call to display method
}

int main() {
    test();
    return 0;
}