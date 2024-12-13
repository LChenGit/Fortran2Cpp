#include <iostream>
#include <string>

// Function that returns the message we want to print, mimicking the Fortran subroutine's behavior.
std::string getMessage() {
    return "ok";
}

int main() {
    std::cout << getMessage() << std::endl;
    return 0;
}