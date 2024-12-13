#include <iostream>
#include <cassert>
#include <sstream>

std::string run_program() {
    std::stringstream buffer;
    int x = 1;
    buffer << x;
    return buffer.str();
}

int main() {
    // Convert the output to a string and assert if it matches "1"
    // Note: We add a space to match the Fortran output exactly, which often includes additional spaces for integers.
    assert(run_program() == "1");
    std::cout << "C++ Test Passed" << std::endl;
    return 0;
}