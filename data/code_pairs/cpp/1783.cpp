#include <gtest/gtest.h>
#include <complex>

// Forward declarations
void p1();
void q1();

// Definitions
void p1() {
    std::complex<float> c5; // Complex variable
    std::complex<float> c6; // Another complex variable
    c5 = c5; // Self-assignment
    c6 = c6; // Self-assignment
}

void q1() {
    float r5; // Real variable
    float r6; // Another real variable
    r5 = r5; // Self-assignment
    r6 = r6; // Self-assignment
}

// Unit tests
TEST(FooTest, SubroutineExecution) {
    // Test to ensure the functions can be called.
    EXPECT_NO_THROW(p1());
    EXPECT_NO_THROW(q1());
}

// Test runner main function
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}