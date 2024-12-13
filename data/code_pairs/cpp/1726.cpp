#include <iostream>
#include <cstdlib> // For std::abort()

class foo {
public:
    foo() : i(0) {}
    virtual void do_it() {
        i = 1;
        std::cout << "FOO::do_it base version" << std::endl;
    }
    virtual int get_it() {
        return i;
    }
protected:
    int i;
};

class foo2 : public foo {
public:
    foo2() : j(0) {}
    void do_it() override {
        i = 2;
        j = 3;
        std::cout << "FOO2::do_it derived version" << std::endl;
    }
    int get_it() override {
        return j;
    }
protected:
    int j;
};

int main() {
    foo2 af2;
    
    af2.do_it();
    if (af2.get_it() != 3) std::abort();

    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}