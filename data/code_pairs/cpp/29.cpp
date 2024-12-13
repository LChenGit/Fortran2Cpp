#include <gtest/gtest.h>
#include <vector>

void one() {
    int xDim = 14; // [-4:9] inclusive gives 14 elements.
    int yDim = 8;
    int zDim = 4; // Adjusted for a specific size for demonstration.

    std::vector<std::vector<std::vector<int>>> a(xDim,
        std::vector<std::vector<int>>(yDim,
            std::vector<int>(zDim, 0))); // Initialized with 0s.

    // Verify allocation - in a real test, you might check sizes or specific expected values
    EXPECT_EQ(a.size(), xDim);
    EXPECT_EQ(a[0].size(), yDim);
    EXPECT_EQ(a[0][0].size(), zDim);
}

TEST(DynamicArrayTest, Allocation) {
    one(); // This test will pass if 'one()' does not throw any exceptions
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}