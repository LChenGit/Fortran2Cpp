#include <iostream>
#include <array>
#include <string>
#include <cassert>

void testArrayInitialization(const std::array<int, 7>& array) {
    for (int i = 0; i < 7; ++i) {
        assert(array[i] == i + 1);
    }
    std::cout << "Array initialization test passed." << std::endl;
}

void testStringSlicing(const std::string& str) {
    assert(str.substr(1, 3) == "bcd");
    std::cout << "Slice 2:4 test passed." << std::endl;

    assert(str.substr(0, 3) == "abc");
    std::cout << "Slice :3 test passed." << std::endl;

    assert(str.substr(4) == "efg");
    std::cout << "Slice 5: test passed." << std::endl;

    assert(str == "abcdefg");
    std::cout << "Full string slice test passed." << std::endl;
}

int main() {
    std::string str = "abcdefg";
    std::array<int, 7> array;

    // Initialize the array
    for (int i = 0; i < 7; ++i) {
        array[i] = i + 1;
    }

    testArrayInitialization(array);
    testStringSlicing(str);

    return 0;
}