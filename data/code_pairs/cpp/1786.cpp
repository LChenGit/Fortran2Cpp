#include <gtest/gtest.h>
#include <array>

void foo(std::array<int, 4>& a) {
    for (int& element : a) {
        if (element != 0) {
            element = 1;
        }
    }
}

TEST(FooTest, MixedZeroAndNonZero) {
    std::array<int, 4> testArray = {0, 2, 0, 3};
    foo(testArray);
    EXPECT_EQ(testArray, (std::array<int, 4>{0, 1, 0, 1}));
}

TEST(FooTest, AllZeros) {
    std::array<int, 4> testArray = {0, 0, 0, 0};
    foo(testArray);
    EXPECT_EQ(testArray, (std::array<int, 4>{0, 0, 0, 0}));
}

TEST(FooTest, AllNonZeros) {
    std::array<int, 4> testArray = {4, 5, -1, 3};
    foo(testArray);
    EXPECT_EQ(testArray, (std::array<int, 4>{1, 1, 1, 1}));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}