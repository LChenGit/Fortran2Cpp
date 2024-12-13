#include <iostream>
#include <gtest/gtest.h>

class t {
public:
    void testsub() const {
        std::cout << "t's test" << std::endl;
    }

    int testfun() const {
        return 1;
    }
};

// Unit tests for class t
TEST(TClassTest, TestSub) {
    t x;
    // Since testsub only prints to the console, there's no direct output to check.
    // Thus, we're assuming its success due to the lack of return values or side effects.
    EXPECT_NO_THROW(x.testsub());
}

TEST(TClassTest, TestFun) {
    t x;
    EXPECT_EQ(1, x.testfun());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}