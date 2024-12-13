// test.cpp
#include <gtest/gtest.h>

// Function that mimics the logic in the Fortran code
int FuncUnderTest() {
    int a = 0; // Initialize 'a'

    if (true) {
        // Intentionally left blank
    } else {
        a = 1;
    }
    return a;
}

// Unit test for the function
TEST(TestSuite, TestCase1) {
    EXPECT_EQ(FuncUnderTest(), 0);
}

// Main function to run the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}