#include <iostream>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

// Function to find the maximum value
int getMaxValue(const std::vector<int>& vec) {
    return *std::max_element(vec.begin(), vec.end());
}

// Main program logic
void runMainProgram() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    int maxValue = getMaxValue(data);
    std::cout << "Maximum Value: " << maxValue << std::endl;
}

// Test case for the getMaxValue function
TEST(MaxValueTest, HandlesPositiveNumbers) {
    std::vector<int> testVec = {1, 2, 3, 4, 5};
    ASSERT_EQ(getMaxValue(testVec), 5);
}

TEST(MaxValueTest, HandlesNegativeNumbers) {
    std::vector<int> testVec = {-5, -4, -3, -2, -1};
    ASSERT_EQ(getMaxValue(testVec), -1);
}

// The main function that runs all the tests
int main(int argc, char **argv) {
    runMainProgram();  // Optionally run the main program logic
    
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}