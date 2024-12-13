// x.h - Header file
#include <memory>

struct x {
    std::unique_ptr<int> i;
    x() : i(nullptr) {}
};

// x_test.cpp - Test file
#include <gtest/gtest.h>
#include "x.h"

TEST(XTest, PointerNotAssociated) {
    x y;
    EXPECT_EQ(y.i, nullptr);
}

TEST(XTest, PointerAssociated) {
    x z;
    int a = 10;
    z.i = std::make_unique<int>(a);
    EXPECT_NE(z.i, nullptr);
    EXPECT_EQ(*z.i, a);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}