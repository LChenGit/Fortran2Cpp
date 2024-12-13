#include <iostream>
#include <vector>
#include <iomanip> // For std::setw and std::setprecision
#include <gtest/gtest.h>

const int dimx = 8;
const int dimy = 6;

void filltab(std::vector<std::vector<float>>& ftab) {
    for (int x = 0; x < dimx; ++x) {
        for (int y = 0; y < dimy; ++y) {
            ftab[x][y] = (x + 1) * 100 + (y + 1); // Adjusted for 0-based indexing
        }
    }
}

void printtab(const std::vector<std::vector<float>>& tab) {
    for (int x = 0; x < dimx; ++x) {
        std::cout << std::setw(3) << x + 1 << "  "; // Adjusted for 0-based indexing and formatted output
        for (int y = 0; y < dimy; ++y) {
            std::cout << std::setw(6) << std::setprecision(1) << std::fixed << tab[x][y] << " ";
        }
        std::cout << std::endl;
    }
}

// Test fixture for setup and teardown
class ArrayTest : public ::testing::Test {
protected:
    std::vector<std::vector<float>> ftab;

    void SetUp() override {
        ftab.resize(dimx, std::vector<float>(dimy));
        filltab(ftab);
    }
};

// Test the filltab function
TEST_F(ArrayTest, FillTabCorrectlyFillsArray) {
    for (int x = 0; x < dimx; ++x) {
        for (int y = 0; y < dimy; ++y) {
            EXPECT_EQ(ftab[x][y], (x + 1) * 100 + (y + 1));
        }
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}