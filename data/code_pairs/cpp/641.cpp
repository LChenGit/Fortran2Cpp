#include <iostream>
#include <memory>
#include <gtest/gtest.h>

class parent {
public:
    virtual int sum(const parent& op) const { return 0; }
    friend int operator+(const parent& op1, const parent& op2) {
        return op1.sum(op2);
    }
};

class child : public parent {
public:
    int sum(const parent& op) const override { return 1; }
};

TEST(ParentChildTest, TestParentAddition) {
    parent m1, m2;
    EXPECT_EQ(0, m1 + m2);
}

TEST(ParentChildTest, TestChildParentAddition) {
    child h1;
    parent m2;
    EXPECT_EQ(1, h1 + m2);
}

TEST(ParentChildTest, TestChildSumMethod) {
    child h1, h2;
    EXPECT_EQ(1, h1.sum(h2));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}