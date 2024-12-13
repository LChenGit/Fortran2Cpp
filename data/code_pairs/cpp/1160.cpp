#include <iostream>
#include <cassert>
#include <cstddef>

// Equivalent to the Fortran module, using a namespace.
namespace c_ptr_tests_9 {

    // Equivalent to the Fortran derived type, using a class.
    class myF90Derived {
    public:
        void* my_c_ptr; // Equivalent to type(c_ptr).

        myF90Derived() : my_c_ptr(nullptr) {} // Constructor initializes my_c_ptr to nullptr.
    };

    // Equivalent to the Fortran subroutine, a function in C++.
    extern "C" void sub0() {
        myF90Derived my_f90_type;
        myF90Derived* my_f90_type_ptr = nullptr;

        my_f90_type.my_c_ptr = nullptr;
        std::cout << "my_f90_type is: " << my_f90_type.my_c_ptr << std::endl;

        my_f90_type_ptr = &my_f90_type;
        std::cout << "my_f90_type_ptr is: " << my_f90_type_ptr->my_c_ptr << std::endl;
    }
} // namespace c_ptr_tests_9

// Main function that also acts as a test driver.
int main() {
    c_ptr_tests_9::sub0();

    // Perform a basic check to ensure pointers are initialized to nullptr.
    c_ptr_tests_9::myF90Derived instance;
    assert(instance.my_c_ptr == nullptr); // Check if initialized correctly.
    std::cout << "C++ Test passed: my_c_ptr is correctly initialized to nullptr." << std::endl;

    return 0;
}