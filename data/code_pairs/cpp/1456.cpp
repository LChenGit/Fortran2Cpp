#include <iostream>
#include <vector>
#include <string>
#include <gtest/gtest.h>

// Function prototype
std::string parsef(const std::vector<std::string>& var);

// Test fixture class
class ParsefTest : public ::testing::Test {
protected:
    std::vector<std::string> var1 = {"a"};
    std::vector<std::string> var2 = {"b", "c"};
};

// Function implementation
std::string parsef(const std::vector<std::string>& var) {
    std::string result;
    for (const auto& str : var) {
        result += str;
    }
    return result;
}

// Test case 1: Single element vector
TEST_F(ParsefTest, SingleElement) {
    EXPECT_EQ(parsef(var1), "a");
}

// Test case 2: Multi-element vector
TEST_F(ParsefTest, MultiElement) {
    EXPECT_EQ(parsef(var2), "bc");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}