#include <gtest/gtest.h>
#include <vector>
#include <array>

TEST(ArrayTest, BasicAssertions) {
    // Setup translated arrays
    std::array<int, 10> n1;
    int n2[10];
    std::array<std::array<std::array<int, 20>, 15>, 5> n3;
    int n4[5][15][20];
    std::vector<std::vector<std::vector<int>>> n5(11, std::vector<std::vector<int>>(31, std::vector<int>(41, 0)));

    // Assign values
    n1[0] = 1;
    n2[9] = 10;
    n3[0][0][0] = 111;
    n4[4][14][19] = 5120;
    n5[0][0][0] = -551520; // Equivalent to n5(-5,-15,-20) in Fortran
    n5[5][15][20] = 551520; // Equivalent to n6(5,15,20) in Fortran

    // Check values
    EXPECT_EQ(n1[0], 1);
    EXPECT_EQ(n2[9], 10);
    EXPECT_EQ(n3[0][0][0], 111);
    EXPECT_EQ(n4[4][14][19], 5120);
    EXPECT_EQ(n5[0][0][0], -551520);
    EXPECT_EQ(n5[5][15][20], 551520);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}