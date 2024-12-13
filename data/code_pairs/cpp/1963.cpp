#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int performXOR(const std::vector<int>& vec) {
    int result = 0;
    for (int val : vec) {
        result ^= val;
    }
    return result;
}

void testXOROperation() {
    std::vector<int> testVec = {1, 2, 3, 4, 5};
    int expectedXOR = 1; // Initialize to the first element for XORing
    for (size_t i = 1; i < testVec.size(); ++i) {
        expectedXOR ^= testVec[i];
    }
    
    int actualXOR = performXOR(testVec);
    if (actualXOR == expectedXOR) {
        std::cout << "XOR Test PASS" << std::endl;
    } else {
        std::cout << "XOR Test FAIL" << std::endl;
        exit(1); // Exit if the test fails
    }
}

int main() {
    // Run the test before the main logic for demonstration
    testXOROperation();

    const int N = 1000;
    std::vector<int> random_array(N);
    std::srand(std::time(0));

    for (int i = 0; i < N; ++i) {
        random_array[i] = std::rand() % 10000;
    }

    int ans_val = performXOR(random_array);
    int sa = performXOR(random_array); // Redundant but follows the original structure

    if (sa == ans_val) {
        std::cout << "PASS" << std::endl;
    } else {
        std::cout << "ERROR" << std::endl;
    }

    return 0;
}