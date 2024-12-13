#include <iostream>
#include <cassert>

void squareNumber(int inputNumber, int &result);

int main() {
    int testInput, expectedResult, actualResult;

    // Test case 1
    testInput = 5;
    expectedResult = 25;
    squareNumber(testInput, actualResult);
    assert(actualResult == expectedResult);
    std::cout << "Test 1 passed." << std::endl;
    
    // Test case 2
    testInput = -3;
    expectedResult = 9;
    squareNumber(testInput, actualResult);
    assert(actualResult == expectedResult);
    std::cout << "Test 2 passed." << std::endl;

    return 0;
}

void squareNumber(int inputNumber, int &result) {
    result = inputNumber * inputNumber;
}