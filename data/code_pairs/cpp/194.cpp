#include <iostream>
#include <vector>
#include <cmath>
#include <gtest/gtest.h>

// Function Declaration
std::vector<std::vector<float>> gen(int order);

// Function Definition
std::vector<std::vector<float>> gen(int order) {
    std::vector<std::vector<float>> matrix(order, std::vector<float>(order + 1));
    for (int i = 0; i < order; ++i) {
        for (int j = 0; j < order + 1; ++j) {
            matrix[i][j] = static_cast<float>((i + 1) * (i + 1) + (j + 1));
        }
    }
    return matrix;
}

// Unit Tests

TEST(GenFunctionTest, GeneratesCorrectMatrix) {
    int order = 3;
    auto result = gen(order);
    for (int i = 0; i < order; ++i) {
        for (int j = 0; j < order + 1; ++j) {
            EXPECT_FLOAT_EQ(result[i][j], static_cast<float>((i + 1) * (i + 1) + (j + 1)));
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}