#ifndef FORCE_IMPL_H
#define FORCE_IMPL_H

#include <iostream>

class ForceInterface {
public:
    virtual ~ForceInterface() {}
    virtual void force() const = 0;
};

class ForceImpl : public ForceInterface {
public:
    void force() const override {
        std::cout << "Force calculation" << std::endl;
    }
};

#endif // FORCE_IMPL_H