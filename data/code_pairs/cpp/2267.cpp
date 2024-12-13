#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <iostream>

class AllType {
public:
    double a;
    std::vector<double> b;

    AllType() : a(0.0), b(2) {}

    AllType& operator=(const AllType& other) {
        if (this != &other) {
            a = other.a;
            b = other.b;
        }
        return *this;
    }

    AllType operator-() const {
        AllType result;
        result.a = -a;
        result.b = std::vector<double>(b.size());
        std::transform(b.begin(), b.end(), result.b.begin(), [](double x) { return -x; });
        return result;
    }
};

TEST(AllTypeTest, UnaryMinusOperator) {
    AllType t1, t2;

    t1.a = 0.5;
    t1.b[0] = 1.0;
    t1.b[1] = 2.0;

    t2 = -t1;

    EXPECT_DOUBLE_EQ(t2.a, -0.5);
    EXPECT_DOUBLE_EQ(t2.b[0], -1.0);
    EXPECT_DOUBLE_EQ(t2.b[1], -2.0);

    t1 = -t1;

    EXPECT_DOUBLE_EQ(t1.a, -0.5);
    EXPECT_DOUBLE_EQ(t1.b[0], -1.0);
    EXPECT_DOUBLE_EQ(t1.b[1], -2.0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}