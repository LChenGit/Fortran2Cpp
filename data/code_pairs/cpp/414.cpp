#include <iostream>
#include <string>

// Function declarations
std::string f();
std::string f(int i);

// Test function declarations
void test_f_no_arg();
void test_f_with_arg();

int main() {
    test_f_no_arg();
    test_f_with_arg();
    return 0;
}

// Function definitions
std::string f() {
    return "absent";
}

std::string f(int i) {
    return "present";
}

// Test function definitions
void test_f_no_arg() {
    std::string result = f();
    if (result == "absent") {
        std::cout << "Test with no arg: PASS" << std::endl;
    } else {
        std::cout << "Test with no arg: FAIL" << std::endl;
    }
}

void test_f_with_arg() {
    std::string result = f(1);
    if (result == "present") {
        std::cout << "Test with arg: PASS" << std::endl;
    } else {
        std::cout << "Test with arg: FAIL" << std::endl;
    }
}