#include <iostream>

class Mod1 {
public:
    virtual void foo(float a) = 0;
    virtual ~Mod1() = default;
};

class Mod1Impl : public Mod1 {
public:
    void foo(float a) override {
        std::cout << "Mod1Impl::foo called with " << a << std::endl;
    }
};

class Mod2 {
public:
    virtual void bar(float a) = 0;
    virtual ~Mod2() = default;
};

class Mod2Impl : public Mod2 {
public:
    void bar(float a) override {
        std::cout << "Mod2Impl::bar called with " << a << std::endl;
    }
};

int main() {
    Mod1Impl mod1;
    Mod2Impl mod2;

    mod1.foo(1.0f);
    mod2.bar(2.0f);

    return 0;
}