#include <iostream>

namespace interface_subroutine {
    // Prototype for subroutine 'sub'
    void sub(int a);
}

// Implementing the 'sub' function
void interface_subroutine::sub(int a) {
    std::cout << "C++: The value of a is " << a << std::endl;
}

int main() {
    // Calling the 'sub' function
    interface_subroutine::sub(10);
    return 0;
}