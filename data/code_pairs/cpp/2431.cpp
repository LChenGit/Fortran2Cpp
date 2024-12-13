#include <cmath>
#include <iostream>
#include <gtest/gtest.h>

// Function to be tested
double RL(double Q) {
    double P = std::pow(Q, 1.0 / 3.0);
    double RL = 0.49 * P * P / (0.6 * P * P + std::log(1.0 + P));
    return RL;
}

// Unit tests
TEST(RLTest, BasicComputations) {
    EXPECT_NEAR(RL(8.0), 0.56022212188197462, 1e-8);
    EXPECT_NEAR(RL(1.0), 0.37892051838045632, 1e-8);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}