// format_test.cpp
#include <gtest/gtest.h>
#include <sstream>
#include <iomanip>

TEST(FormatTest, IntegerFormatting) {
    int intValue1 = 123, intValue2 = 4;
    std::stringstream ss;

    // Simulate FORMAT (I12, i1) from Fortran
    ss << std::setw(12) << intValue1 << std::setw(1) << intValue2;

    // Checking against expected output
    EXPECT_EQ(ss.str(), "         1234");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}