#include <iostream>

namespace m {
    class t {
    public:
        // Constructor, destructor, and other member functions can be defined here.
    };
}

class t_global { // This is in the global namespace, separate from m::t
public:
    // Constructor, destructor, and other member functions can be defined here.
};

int main() {
    m::t object1; // object of class t defined inside namespace m
    t_global object2;  // object of class t_global defined in the global namespace

    std::cout << "C++ test passed." << std::endl;

    return 0;
}