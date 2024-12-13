#include <gtest/gtest.h>
#include <array>
#include <cmath>
#include <functional>

std::array<float, 2> triple(int n, std::array<float, 2> x) {
    return {3.0f * x[0], 3.0f * x[1]};
}

class ProcPointerType {
public:
    std::function<std::array<float, 2>(int, std::array<float, 2>)> f;

    ProcPointerType() {}

    void assign(std::function<std::array<float, 2>(int, std::array<float, 2>)> func) {
        f = func;
    }
};

TEST(TripleFunctionTest, TripleTest) {
    ProcPointerType ppt;
    ppt.assign(triple);

    auto tres = ppt.f(2, {2.0f, 4.0f});
    EXPECT_NEAR(tres[0], 6.0f, 1E-3);
    EXPECT_NEAR(tres[1], 12.0f, 1E-3);

    tres = ppt.f(2, {3.0f, 5.0f});
    EXPECT_NEAR(tres[0], 9.0f, 1E-3);
    EXPECT_NEAR(tres[1], 15.0f, 1E-3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}