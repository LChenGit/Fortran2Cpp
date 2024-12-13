#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>

// Function to replicate the Fortran functionality for formatting
std::string formatIntegerWithSpaces() {
    std::ostringstream oss;
    // Adding space before and after the number to replicate the Fortran behavior
    oss << ' ' << std::setw(4) << 1 << ' ';
    return oss.str();
}

// Unit Test Case
TEST(FortranTranslationTest, FormatCheck) {
    std::string expected = "    1 ";
    ASSERT_EQ(formatIntegerWithSpaces(), expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}