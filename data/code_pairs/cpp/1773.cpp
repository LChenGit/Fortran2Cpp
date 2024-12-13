#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include <iomanip>

// Function to be tested
std::string formatNumber(double number) {
    std::ostringstream oss;
    oss << std::scientific << std::setprecision(2) << number;
    return oss.str();
}

// Test case
TEST(FormatNumberTest, FormatsCorrectly) {
    EXPECT_EQ("3.00e+00", formatNumber(3.0));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}