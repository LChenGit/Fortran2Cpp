#include <iostream>
#include <string>
#include <cassert>

// Translation of the Fortran functions into C++ functions
std::string test1(int n) {
    return std::string(n, ' ');
}

std::string test2() {
    return " ";
}

std::string test3() {
    return "";
}

std::string test4(int n) {
    return std::string(n, ' ');
}

std::string test5() {
    return " ";
}

std::string test6() {
    return "";
}

// Basic testing framework
void assertEqual(const std::string& lhs, const std::string& rhs, const std::string& testName) {
    assert(lhs == rhs && "Test failed");
    std::cout << testName << " passed." << std::endl;
}

int main() {
    // Run tests
    assertEqual(test1(5), "     ", "Test1");
    assertEqual(test2(), " ", "Test2");
    assertEqual(test3(), "", "Test3");
    assertEqual(test4(5), "     ", "Test4");
    assertEqual(test5(), " ", "Test5");
    assertEqual(test6(), "", "Test6");
    
    std::cout << "All tests passed successfully." << std::endl;
    
    return 0;
}