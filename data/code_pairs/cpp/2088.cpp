#include <iostream>
#include <memory>

class T {
public:
    T() = default;
    virtual ~T() = default;
};

class Mod {
public:
    void s1(T& x) {
        std::cout << "s1 called" << std::endl;
    }

    template<typename AnyType>
    void s2(std::unique_ptr<AnyType>& x) {
        std::cout << "s2 called with integer" << std::endl;
    }
};