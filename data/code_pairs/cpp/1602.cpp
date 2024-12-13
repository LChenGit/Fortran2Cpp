#include <iostream>
#include <vector>
#include <utility> // For std::pair

bool evenly_divis(int a) {
    for (int i = 1; i <= 20; i++) {
        if (a % i != 0) {
            return false;
        }
    }
    return true;
}

void runTests() {
    std::vector<std::pair<int, bool>> testCases = {
        {10, false}, // 10 is not evenly divisible by all numbers from 1 to 20
        {2520, true} // 2520 is evenly divisible by all numbers from 1 to 20
    };

    std::cout << "Running unit tests..." << std::endl;
    for (const auto& testCase : testCases) {
        int input = testCase.first;
        bool expected = testCase.second;
        bool result = evenly_divis(input);
        if (result == expected) {
            std::cout << "Test with input " << input << " passed." << std::endl;
        } else {
            std::cout << "Test with input " << input << " failed!" << std::endl;
        }
    }
}

int main() {
    runTests();

    int i = 1;
    while (!evenly_divis(i)) {
        i++;
    }
    std::cout << "The smallest number evenly divisible by all numbers from 1 to 20 is: " << i << std::endl;

    return 0;
}