#include <iostream>
#include <array>
#include <cstdlib> // For std::abort

// Declaration for huj() in huj_mod namespace
namespace huj_mod {
    std::array<int, 3> huj() {
        return {1, 2, 3};
    }
}

// Declaration for hoj()
std::array<int, 3> hoj() {
    return {1, 2, 3};
}

// A simple assert function for testing
void assertEqual(const std::array<int, 3>& result, const std::array<int, 3>& expected, const std::string& testName) {
    if (result != expected) {
        std::cout << testName << " failed." << std::endl;
        std::abort();
    } else {
        std::cout << testName << " passed." << std::endl;
    }
}

// Test functions
void testHoj() {
    std::array<int, 3> expected = {1, 2, 3};
    assertEqual(hoj(), expected, "hoj()");
}

void testHuj() {
    std::array<int, 3> expected = {1, 2, 3};
    assertEqual(huj_mod::huj(), expected, "huj_mod::huj()");
}

// Main function
int main() {
    testHoj();
    testHuj();
    return 0;
}