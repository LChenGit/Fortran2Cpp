#include <iostream>
#include <memory>

class Base {
public:
    int x;
    Base() : x(0) {}
    virtual ~Base() = default;
    virtual int getval() const = 0;
};

class ChildAType : public Base {
public:
    ChildAType(int x) { this->x = x; }
    int getval() const override { return x; }
    static std::shared_ptr<ChildAType> alias_t(ChildAType& self) {
        return std::shared_ptr<ChildAType>(&self, [](ChildAType*){});
    }
    static std::shared_ptr<ChildAType> alias_c(const ChildAType& self) {
        return std::shared_ptr<ChildAType>(const_cast<ChildAType*>(&self), [](ChildAType*){});
    }
};

class ChildBType : public Base {
public:
    ChildBType(int x) { this->x = x; }
    int getval() const override { return x * 2; }
};

int main() {
    ChildAType a(10);
    ChildBType b(10);

    std::cout << "Testing getval() for ChildAType: ";
    std::cout << ((a.getval() == 10) ? "PASS" : "FAIL") << std::endl;

    std::cout << "Testing getval() for ChildBType: ";
    std::cout << ((b.getval() == 20) ? "PASS" : "FAIL") << std::endl;

    auto aliasT = ChildAType::alias_t(a);
    std::cout << "Testing alias_t for ChildAType: ";
    std::cout << ((aliasT->getval() == 10) ? "PASS" : "FAIL") << std::endl;

    auto aliasC = ChildAType::alias_c(a);
    std::cout << "Testing alias_c for ChildAType: ";
    std::cout << ((aliasC->getval() == 10) ? "PASS" : "FAIL") << std::endl;

    return 0;
}