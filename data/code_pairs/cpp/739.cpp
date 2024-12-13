#include <gtest/gtest.h>
#include <sstream>
#include <iomanip>
#include <string>

// Function to format the number in scientific notation (mimicking Fortran's E format)
std::string formatNumberE(double r) {
    std::ostringstream ss;
    ss << std::scientific << std::setprecision(2) << r;
    return ss.str();
}

// Function to format the number in scientific notation with uppercase (mimicking Fortran's D format)
std::string formatNumberD(double r) {
    std::ostringstream ss;
    ss << std::scientific << std::uppercase << std::setprecision(2) << r;
    return ss.str();
}

TEST(NumberFormattingTest, ScientificNotationE) {
    double r = 1.0;
    std::string expectedE = "1.00e+00";
    ASSERT_EQ(formatNumberE(r), expectedE);
}

TEST(NumberFormattingTest, ScientificNotationD) {
    double r = 1.0;
    std::string expectedD = "1.00E+00";
    ASSERT_EQ(formatNumberD(r), expectedD);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}