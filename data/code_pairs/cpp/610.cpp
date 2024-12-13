#include <iostream>
#include <cassert>

class inversion_grid {
public:
    bool is_initialized = false;
};

class error_message {
public:
    bool has_error = false;
};

class CreateShoreLinesF2pyVar {
public:
    inversion_grid invgrid;
    error_message errmsg;
    bool invgrid_created = false;

    CreateShoreLinesF2pyVar() {}
};

void testClass() {
    CreateShoreLinesF2pyVar obj;
    assert(!obj.invgrid_created); // Test initial state

    obj.invgrid.is_initialized = true;
    assert(obj.invgrid.is_initialized); // Test functionality

    obj.errmsg.has_error = true;
    assert(obj.errmsg.has_error); // Test functionality

    std::cout << "All tests passed." << std::endl;
}

int main() {
    testClass();
    return 0;
}