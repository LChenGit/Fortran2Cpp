#include <vector>
#include <cstddef> // for std::size_t
#include <gtest/gtest.h>

class Deri23_I {
public:
    static void deri23(const std::vector<double>& F,
                       const std::vector<double>& FD,
                       const std::vector<double>& E,
                       const std::vector<double>& FCI,
                       std::vector<double>& CMO,
                       std::vector<double>& EMO) {
        for(std::size_t i = 0; i < F.size(); ++i) {
            CMO[i] = F[i] * 2.0;  // Example operation
            EMO[i] = F[i] + 1.0;  // Example operation
        }
    }
};

TEST(Deri23ITest, BasicTest) {
    std::vector<double> F = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> FD = {5.0, 4.0, 3.0, 2.0, 1.0};
    std::vector<double> E = {2.0, 2.0, 2.0, 2.0, 2.0};
    std::vector<double> FCI = {1.0, 1.0, 1.0, 1.0, 1.0};
    std::vector<double> CMO(5);
    std::vector<double> EMO(5);

    Deri23_I::deri23(F, FD, E, FCI, CMO, EMO);

    std::vector<double> expectedCMO = {2.0, 4.0, 6.0, 8.0, 10.0};
    std::vector<double> expectedEMO = {2.0, 3.0, 4.0, 5.0, 6.0};

    EXPECT_EQ(expectedCMO, CMO);
    EXPECT_EQ(expectedEMO, EMO);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}