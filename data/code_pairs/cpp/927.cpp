#include <iostream>
#include <vector>
#include <string>

// C++ function definition
int args_loc(const std::vector<std::string>& array, const std::string& elt) {
    for (size_t i = 0; i < array.size(); ++i) {
        if (array[i] == elt) {
            return static_cast<int>(i + 1); // Convert 0-based index to 1-based to match Fortran behavior
        }
    }
    return 0; // Return 0 if not found, matching Fortran behavior
}

// C++ unit test code using Google Test
#include <gtest/gtest.h>

TEST(ArgsLocTest, ElementFound) {
    std::vector<std::string> testArray = {"apple", "banana", "cherry"};
    EXPECT_EQ(2, args_loc(testArray, "banana")); // Expect index 2 (1-based)
}

TEST(ArgsLocTest, ElementNotFound) {
    std::vector<std::string> testArray = {"apple", "banana", "cherry"};
    EXPECT_EQ(0, args_loc(testArray, "orange")); // Element not found
}

TEST(ArgsLocTest, EmptyArray) {
    std::vector<std::string> emptyArray = {};
    EXPECT_EQ(0, args_loc(emptyArray, "apple")); // Empty array
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}