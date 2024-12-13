#ifndef UNITVALUE_MODULE_HPP
#define UNITVALUE_MODULE_HPP

#include <string>

class UnitValue {
public:
    float value;
    std::string unit;

    UnitValue(float val = 0.0, std::string unt = "") : value(val), unit(unt) {}

    // Overload the + operator
    UnitValue operator+(const UnitValue& other) const {
        // Assuming both values are in the same unit for simplicity
        return UnitValue(value + other.value, unit);
    }
};

#endif // UNITVALUE_MODULE_HPP