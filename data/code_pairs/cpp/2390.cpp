#include <iostream>
#include <string>
#include <memory>
#include <gtest/gtest.h>

// Define the A type
struct A {
    int X;
    std::unique_ptr<int> y;
    std::unique_ptr<std::string> c;

    // Constructor to initialize A
    A(int x = 0, int y_val = 0, const std::string& c_val = "") : X(x) {
        if (y_val != 0) {
            y = std::make_unique<int>(y_val);
        }
        if (!c_val.empty()) {
            c = std::make_unique<std::string>(c_val);
        }
    }
};

// Test cases
TEST(FortranToCppTest, TestMe) {
    A Me(1, 2, "correctly allocated");

    ASSERT_EQ(Me.X, 1);
    ASSERT_TRUE(Me.y);
    ASSERT_EQ(*Me.y, 2);
    ASSERT_TRUE(Me.c);
    ASSERT_EQ(Me.c->length(), 19);
    ASSERT_EQ(*Me.c, "correctly allocated");
}

TEST(FortranToCppTest, TestEa) {
    A Ea;

    Ea.X = 9;
    Ea.y = std::make_unique<int>(42);
    Ea.c = std::make_unique<std::string>("13 characters");

    ASSERT_EQ(Ea.X, 9);
    ASSERT_TRUE(Ea.y);
    ASSERT_EQ(*Ea.y, 42);
    ASSERT_TRUE(Ea.c);
    ASSERT_EQ(Ea.c->length(), 13);
    ASSERT_EQ(*Ea.c, "13 characters");

    Ea.y.reset();
    Ea.c.reset();

    ASSERT_FALSE(Ea.y);
    ASSERT_FALSE(Ea.c);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}