// myFunction.cpp
#include <iostream>
#include <cstddef> // for std::size_t

extern "C" {
    void myFunction(float& f, std::size_t d) {
        std::cout << "f=" << f << " d=" << d << std::endl;
    }
}