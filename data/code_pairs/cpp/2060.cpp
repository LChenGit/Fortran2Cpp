#include <array>
#include <gtest/gtest.h>

// Assuming these are defined in the global scope
int c1 = 1, c2 = 1, c3 = 1;

void foo(std::array<std::array<float, 2>, 100>& tmp1, std::array<float, 100>& tmp2, std::array<float, 100>& tmp3) {
    c2 = c3; // Mimic Fortran behavior
    bool cond = (c1 == 1 && c3 == 1);

    for (int i = 0; i < 100; ++i) {
        if (cond) {
            tmp2[i] = tmp1[i][0] / tmp1[i][1];
        }
    }

    for (int i = 0; i < 100; ++i) {
        if (cond) {
            tmp3[i] = tmp2[i];
        }
    }
}

TEST(FooTest, HandlesSimpleCase) {
    std::array<std::array<float, 2>, 100> tmp1;
    std::array<float, 100> tmp2, tmp3;
    
    // Initialize tmp1 for testing
    for (int i = 0; i < 100; ++i) {
        tmp1[i][0] = static_cast<float>(i + 1);
        tmp1[i][1] = static_cast<float>(i + 2);
    }
    
    // Call the function
    foo(tmp1, tmp2, tmp3);
    
    // Check results
    for (int i = 0; i < 100; ++i) {
        EXPECT_FLOAT_EQ(tmp2[i], tmp1[i][0] / tmp1[i][1]);
        EXPECT_FLOAT_EQ(tmp3[i], tmp2[i]);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}