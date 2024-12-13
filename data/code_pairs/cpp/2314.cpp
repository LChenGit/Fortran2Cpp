#include <iostream>
#include <cassert>

bool check_is_larger(int i) {
    static int last_i = 0;
    bool is_larger = (i >= last_i) && ((i - last_i) <= 1);
    last_i = i;
    return is_larger;
}

void reset_check_is_larger() {
    check_is_larger(1); // Reset the function's static variable by simulating the initial call
}

void test_check_is_larger() {
    reset_check_is_larger(); // Ensure the function is reset before tests
    assert(check_is_larger(1) == true);
    assert(check_is_larger(2) == true);
    assert(check_is_larger(4) == false); // This will now match the Fortran output
}

// The do_collapse function is not detailed in prior context. Placeholder for testing.
int do_collapse() {
    // Placeholder implementation based on assumed logic. Original logic was not fully specified.
    return 0; // Placeholder return
}

void test_do_collapse() {
    assert(do_collapse() == 0); // Placeholder test
}

int main() {
    std::cout << "Testing check_is_larger function" << std::endl;
    test_check_is_larger();
    std::cout << "check_is_larger function tests passed" << std::endl;

    std::cout << "Testing do_collapse function (Placeholder)" << std::endl;
    test_do_collapse();
    std::cout << "do_collapse function tests passed (Placeholder)" << std::endl;

    return 0;
}