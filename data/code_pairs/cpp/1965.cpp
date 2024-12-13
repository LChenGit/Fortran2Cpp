#include <iostream>
#include <vector>

int calculateSum(const std::vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum;
}

void testCalculateSum();

int main() {
    // Example usage
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::cout << "Sum = " << calculateSum(arr) << std::endl;

    // Call the test function
    testCalculateSum();

    return 0;
}

void testCalculateSum() {
    // Test case 1
    std::vector<int> testArray = {1, 2, 3, 4, 5}; // Expected sum is 15
    int expectedSum = 15;
    int actualSum = calculateSum(testArray);
    if (actualSum == expectedSum) {
        std::cout << "Test case 1 passed." << std::endl;
    } else {
        std::cout << "Test case 1 failed. Expected " << expectedSum << ", but got " << actualSum << "." << std::endl;
    }
}