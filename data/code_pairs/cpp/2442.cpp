#include <complex>
#include <iostream>
#include <gtest/gtest.h>

// Equivalent C++ functions
int f1(int x, int y) {
    return x + y;
}

std::complex<float> f2(std::complex<float> x) {
    return x;  // Directly return input for simplicity
}

float f2b(float x, float y) {
    return x + y;
}

// Unit tests for the C++ functions
TEST(FortranToCppTest, TestF1) {
    EXPECT_EQ(f1(1, 2), 3);
}

TEST(FortranToCppTest, TestF2) {
    std::complex<float> cx(1.1f, 2.2f);
    EXPECT_EQ(f2(cx), std::complex<float>(1.1f, 2.2f));
}

TEST(FortranToCppTest, TestF2B) {
    EXPECT_FLOAT_EQ(f2b(1.1f, 2.2f), 3.3f);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}