#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <cstdlib>

struct Obj {
    float array[10][10];
    std::vector<std::vector<float>> array2;

    Obj(int dim1, int dim2) : array2(dim1, std::vector<float>(dim2)) {}
};

class ObjTest : public ::testing::Test {
protected:
    Obj obj1 = Obj(10, 10);
    void SetUp() override {
        int val = 1;
        for (auto& row : obj1.array) {
            std::generate(std::begin(row), std::end(row), [&val]() { return val++; });
        }

        val = 1;
        for (auto& row : obj1.array2) {
            std::generate(row.begin(), row.end(), [&val]() { return val++; });
        }
    }
};

TEST_F(ObjTest, ArrayInitialization) {
    float* arrayPtr = &obj1.array[0][0];
    for (int i = 1; i <= 100; ++i) {
        EXPECT_FLOAT_EQ(arrayPtr[i-1], static_cast<float>(i));
    }
}

TEST_F(ObjTest, Array2Initialization) {
    std::vector<float> flatArray2;
    for (const auto& row : obj1.array2) {
        flatArray2.insert(flatArray2.end(), row.begin(), row.end());
    }
    float* array2Ptr = flatArray2.data();
    for (int i = 1; i <= 100; ++i) {
        EXPECT_FLOAT_EQ(array2Ptr[i-1], static_cast<float>(i));
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}