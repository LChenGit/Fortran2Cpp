#ifndef MYNML_H
#define MYNML_H

#include <iostream>

struct MyNml {
    float x;
    
    MyNml() : x(1.0f) {} // Constructor

    void print() {
        std::cout << "x = " << x << std::endl;
    }
};

#endif // MYNML_H