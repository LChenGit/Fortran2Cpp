// main.cpp
#include <iostream>
#include <gtest/gtest.h>

int great_rsd_add(int kk1, int ii1) {
    return kk1 + ii1;
}

TEST(GreatRsdTest, HandlesAddition) {
    EXPECT_EQ(great_rsd_add(2, 3), 5);
    EXPECT_EQ(great_rsd_add(-1, -1), -2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}