#ifndef WENOOFF_HPP
#define WENOOFF_HPP

#include <iostream>
#include <memory>

class WenoConstructor {
public:
    virtual ~WenoConstructor() {}
};

class WenoConstructorUpwind : public WenoConstructor {};

class WenoInterpolator {
public:
    virtual ~WenoInterpolator() {}
    virtual void interpolate(const WenoConstructor& constructor) = 0;
};

class WenoInterpolatorUpwind : public WenoInterpolator {
public:
    void interpolate(const WenoConstructor& constructor) override {
        std::cout << "Interpolating using upwind method." << std::endl;
    }
};

class WenoFactory {
public:
    static std::unique_ptr<WenoInterpolator> create(const WenoConstructor& constructor) {
        if (dynamic_cast<const WenoConstructorUpwind*>(&constructor)) {
            return std::make_unique<WenoInterpolatorUpwind>();
        }
        return nullptr;
    }
};

#endif // WENOOFF_HPP