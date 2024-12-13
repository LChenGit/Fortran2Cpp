// protmod.cpp
#include <iostream>
#include <memory>

class ProtMod {
protected:
    int a;
    int at;
    std::shared_ptr<int> ap;

public:
    ProtMod() : a(0), at(0), ap(std::make_shared<int>(0)) {}

    void set_values() {
        a = 10;
        at = 20;
        ap = std::make_shared<int>(30); // Directly set shared_ptr to hold the value 30
        at = *ap;  // Ensure 'at' has the updated value to mimic Fortran's behavior
    }

    void print_values() const {
        std::cout << "Value of a: " << a << std::endl;
        std::cout << "Value of at: " << at << std::endl;
        std::cout << "Value of ap (points to at): " << *ap << std::endl;
    }
};

int main() {
    ProtMod protModInstance;
    protModInstance.set_values();
    protModInstance.print_values();

    return 0;
}