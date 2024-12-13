#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include <cassert>

std::vector<float> triple(int n, const std::vector<float>& x) {
    std::vector<float> tre(2);
    tre[0] = 3.0f * x[0];
    tre[1] = 3.0f * x[1];
    return tre;
}

using ProcPointerType = std::function<std::vector<float>(int, const std::vector<float>&)>;

void runTests() {
    ProcPointerType f = triple;
    std::vector<float> result;
    std::vector<float> expected;

    // Test 1
    result = f(2, {2.0f, 4.0f});
    expected = {6.0f, 12.0f};
    assert(std::abs(result[0] - expected[0]) < 1E-3 && std::abs(result[1] - expected[1]) < 1E-3);
    std::cout << "Test 1 Passed" << std::endl;

    // Test 2
    result = f(2, {3.0f, 5.0f});
    expected = {9.0f, 15.0f};
    assert(std::abs(result[0] - expected[0]) < 1E-3 && std::abs(result[1] - expected[1]) < 1E-3);
    std::cout << "Test 2 Passed" << std::endl;
}

int main() {
    runTests();
    return 0;
}