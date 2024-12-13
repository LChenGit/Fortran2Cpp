#include <gtest/gtest.h>
#include <vector>
#include <cmath>

double sqdist(double x1, double y1, double z1, double x2, double y2, double z2, int ind, int MAXROT, const std::vector<std::vector<std::vector<double>>>& rotmat) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    double dz = z1 - z2;
    double result = 0.0;

    for (int i = 0; i < 3; ++i) {
        double cont = rotmat[ind][i][0] * dx
                    + rotmat[ind][i][1] * dy
                    + rotmat[ind][i][2] * dz;
        result += cont * cont;
    }

    return result;
}

TEST(SqDistTest, BasicTest) {
    double x1 = 1.0, y1 = 2.0, z1 = 3.0;
    double x2 = 4.0, y2 = 5.0, z2 = 6.0;
    int ind = 0; // Note: Fortran is 1-based index, C++ is 0-based.
    int MAXROT = 3;

    std::vector<std::vector<std::vector<double>>> rotmat(MAXROT, std::vector<std::vector<double>>(3, std::vector<double>(3, 0.0)));

    // Initialize the rotation matrix to identity matrix for simplicity
    for (int i = 0; i < 3; ++i) {
        rotmat[0][i][i] = 1.0;
    }

    double result = sqdist(x1, y1, z1, x2, y2, z2, ind, MAXROT, rotmat);
    double expected = 27.0; // The squared distance with the given values

    EXPECT_DOUBLE_EQ(result, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}