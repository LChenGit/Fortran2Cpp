#include <gtest/gtest.h>
#include <iostream>
#include <array>
#include <cstdlib>
#include <algorithm>

const int N = 5;
std::array<std::array<int, N>, N> A;

void FOO(int K) {
    int B;
    A[0][0] = 1;

    while (true) {
        B = 0;
        
        for (int I = 0; I < K; ++I) {
            for (int J = 0; J < K; ++J) {
                B += A[I][J];
            }
            A[I][I] *= 2;
        }
        
        if (B >= 3) {
            return;
        }
    }
}

void ABORT() {
    std::cerr << "Abort called!" << std::endl;
    std::exit(EXIT_FAILURE);
}

TEST(FOOTest, BasicAssertions) {
    A.fill({0});
    FOO(2);

    // Check if A[0][0] is 8
    EXPECT_EQ(A[0][0], 8) << "A[0][0] should be 8";

    // Set A[0][0] to 0
    A[0][0] = 0;

    // Check if all elements of A are zero
    bool all_zero = std::all_of(A.begin(), A.end(), [](const std::array<int, N>& row) {
        return std::all_of(row.begin(), row.end(), [](int val) { return val == 0; });
    });

    EXPECT_TRUE(all_zero) << "All elements of A should be zero";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}