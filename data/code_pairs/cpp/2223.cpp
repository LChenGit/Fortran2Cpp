#include <array>
#include <cmath>
#include <gtest/gtest.h>

// Function to be tested
void fi_a3(const std::array<double, 3>& r, std::array<double, 3>& p) {
    p[0] = r[0] + r[1] + r[2];
    p[1] = std::pow(r[0], 2) + std::pow(r[1], 2) + std::pow(r[2], 2);
    p[2] = std::pow(r[0], 3) + std::pow(r[1], 3) + std::pow(r[2], 3);
}

// Unit test
TEST(FiA3Test, CorrectCalculation) {
    std::array<double, 3> r = {1.0, 2.0, 3.0};
    std::array<double, 3> p;
    std::array<double, 3> expected_p = {6.0, 14.0, 36.0};

    fi_a3(r, p);

    for (size_t i = 0; i < p.size(); ++i) {
        EXPECT_NEAR(p[i], expected_p[i], 1e-6);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}