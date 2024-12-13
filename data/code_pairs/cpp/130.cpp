#include <gtest/gtest.h>
#include <array>

// Logic to be tested
void modifyArray(std::array<int, 5>& a, std::array<int, 5>& b) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != 1) {
            b[i] = 2;
        }
        // No need to explicitly set b[i] = 0 when a[i] == 1 due to initialization
    }
}

// Unit Test
TEST(ModifyArrayTest, CorrectModification) {
    std::array<int, 5> a = {1, 2, 3, 4, 5};
    std::array<int, 5> b = {0, 0, 0, 0, 0};
    const std::array<int, 5> expected = {0, 2, 2, 2, 2};

    modifyArray(a, b);

    EXPECT_EQ(b, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}