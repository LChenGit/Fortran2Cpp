#include <iostream>
#include <array>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <cstdlib>

void foo(std::array<std::string, 4>& chr1, std::array<std::string, 4>& chr2) {
    chr2 = chr1;
}

void test_foo() {
    // Test 1: Direct assignment
    std::array<std::string, 4> c1 = {"abcd", "efgh", "ijkl", "mnop"};
    std::array<std::string, 4> c2;
    foo(c1, c2);
    assert(c1 == c2);
    std::cout << "Test 1 Passed" << std::endl;
}

int main() {
    test_foo();
    return 0;
}