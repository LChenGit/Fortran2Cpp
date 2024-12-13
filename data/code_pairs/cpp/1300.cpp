// test.cpp
#include <gtest/gtest.h>
#include <complex>

int k;
float* p1 = nullptr;
std::complex<float> c;
std::complex<float> d[10];

TEST(OpenACCTest, PrivateVariable) {
    int i = 0;

    #pragma acc parallel private(i)
    {
        i = 10; // This change will not reflect outside the parallel region
    }
    // i should remain 0 outside the parallel region due to private clause
    ASSERT_EQ(i, 0);
}

TEST(OpenACCTest, FirstPrivateArray) {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    #pragma acc parallel firstprivate(a)
    {
        a[0] = 20; // This change will not affect the original array outside the parallel region
    }
    // a[0] should remain 1 outside the parallel region due to firstprivate clause
    ASSERT_EQ(a[0], 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}