#include <iostream>
#include <memory>
#include <array>
#include <gtest/gtest.h>

struct x {
    std::shared_ptr<int[]> p; // Pointer to a dynamically-sized array of integers
    std::array<int, 3> q; // Fixed-size array of 3 integers
};

TEST(XStructTest, IntegerSizeInQ) {
    x myX;
    EXPECT_EQ(sizeof(myX.q[0]), sizeof(int)) << "The size of integer in 'q' should match sizeof(int)";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}