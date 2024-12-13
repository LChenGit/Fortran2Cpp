// globalvar_mod.cpp
#include <cassert>
#include <iostream>

namespace globalvar_mod {
    int xstop;
}

void test_xstop() {
    globalvar_mod::xstop = 5;
    assert(globalvar_mod::xstop == 5);
    std::cout << "Test passed: xstop is 5." << std::endl;
}

int main() {
    test_xstop();
    return 0;
}