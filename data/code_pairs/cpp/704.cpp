#include <iostream>

class geoutg_I {
public:
    virtual void geoutg(int IPRT) = 0; // Pure virtual function
    virtual ~geoutg_I() {} // Virtual destructor for proper cleanup
};

class MyGeoutg : public geoutg_I {
public:
    void geoutg(int IPRT) override {
        std::cout << "IPRT = " << IPRT << std::endl;
    }
};