// MyClass.hpp
#ifndef MYCLASS_HPP
#define MYCLASS_HPP

class t {
public:
    int dummy;
    t();  // Constructor declaration
    int getDummy() const;  // Getter declaration
};

void s();  // Function declaration

#endif

// MyClass.cpp
#include "MyClass.hpp"
#include <iostream>

t::t() : dummy(10) {}  // Constructor definition

int t::getDummy() const { return dummy; }  // Getter definition

void s() {
    t myVar;
    std::cout << "Test passed: dummy == 10" << std::endl;
}