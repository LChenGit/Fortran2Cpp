#include <iostream>

namespace types {

class tp4 {
private:
    float x = 0.0f;
    int i = 0;

public:
    tp4() = default;
};

class tp3 {
private:
    int i = 0;

public:
    float x = 0.0f;
    tp3() = default;
};

class tp2 {
public:
    tp3 t;
};

class tp1 {
public:
    int i = 0;
    tp2 t;
};

} // namespace types

namespace nml {
using namespace types;

class tp5 {
public:
    tp4 t;
};

tp1 t1;
tp4 t4;

void y() {
    tp2 y2;
    tp3 y3;
    std::cout << "Subroutine y executed." << std::endl;
}

} // namespace nml

int main() {
    using namespace nml;

    tp5 t5;

    std::cout << "Main program executed." << std::endl;

    // Assuming z is somehow called or used
    // z();

    return 0;
}