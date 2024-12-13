#include <iostream>
#include <vector>
#include <memory>
#include <gtest/gtest.h>

// Define the structure equivalent to the Fortran type
struct t {
    int ii = 55;
};

// Function f1 equivalent
std::shared_ptr<t> f1() {
    auto res = std::make_shared<t>();
    res->ii = 123;
    return res;
}

// Function f2 equivalent
std::vector<std::shared_ptr<t>> f2() {
    std::vector<std::shared_ptr<t>> res(3);
    for (int i = 0; i < 3; ++i) {
        res[i] = std::make_shared<t>();
        res[i]->ii = -11 * (i + 1);
    }
    return res;
}

TEST(FortranToCppTest, TestF1) {
    auto p1 = f1();
    EXPECT_EQ(p1->ii, 123);
}

TEST(FortranToCppTest, TestF2) {
    auto p2 = f2();
    std::vector<int> expected_values = {-11, -22, -33};
    for (int i = 0; i < 3; ++i) {
        EXPECT_EQ(p2[i]->ii, expected_values[i]);
    }
}

TEST(FortranToCppTest, Test2DArray) {
    std::vector<std::vector<std::shared_ptr<t>>> p3(2, std::vector<std::shared_ptr<t>>(3));
    auto f2_res = f2();
    for (int i = 0; i < 3; ++i) {
        p3[1][i] = f2_res[i];
    }
    std::vector<int> expected_values = {-11, -22, -33};
    for (int i = 0; i < 3; ++i) {
        EXPECT_EQ(p3[1][i]->ii, expected_values[i]);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}