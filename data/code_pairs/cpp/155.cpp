#include <gtest/gtest.h>
#include <array>
#include <vector>

// Define the NoBindMod class
class NoBindMod {
public:
    static double Func1() {
        return 0.0;
    }

    static double Func2() {
        return 0.0;
    }

    static double Func3() {
        return 0.0;
    }
};

// Unit tests for the NoBindMod class
TEST(NoBindModTest, TestFunc1) {
    EXPECT_NEAR(NoBindMod::Func1(), 0.0, 1.0E-10);
}

TEST(NoBindModTest, TestFunc2) {
    EXPECT_NEAR(NoBindMod::Func2(), 0.0, 1.0E-10);
}

TEST(NoBindModTest, TestFunc3) {
    EXPECT_NEAR(NoBindMod::Func3(), 0.0, 1.0E-10);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}