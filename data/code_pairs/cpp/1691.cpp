#include <iostream>

namespace c_funloc_tests_5 {
    void sub1();
    int func0(int desired_retval);

    void sub0() {
        void (*my_c_funptr)() = nullptr;
        int (*my_c_funcptr)(int) = nullptr;

        my_c_funptr = &sub1;
        my_c_funptr(); // Calls sub1

        my_c_funcptr = &func0;
        std::cout << "Result of func0: " << my_c_funcptr(42) << std::endl;
    }

    void sub1() {
        std::cout << "sub1 called" << std::endl;
    }

    int func0(int desired_retval) {
        return desired_retval;
    }
} // namespace c_funloc_tests_5