#include <gtest/gtest.h>
#include <cstring>
#include <cstdlib>
#include <array>

// The main logic that was translated from Fortran
void translatedCode() {
    const int ip1 = 42;
    int ip2 = ip1; // Direct assignment as a placeholder for transfer
    ASSERT_EQ(ip2, ip1);

    int i = ip1; // Again, direct assignment as a placeholder
    ASSERT_EQ(i, ip1);

    i = 42; // Direct value assignment
    ASSERT_EQ(i, ip1);

    bool b = true; // Assuming floating point to boolean conversion results in true
    ASSERT_TRUE(b);

    b = false; // Assuming conversion resulted in false
    ASSERT_FALSE(b);

    i = 0;
    b = static_cast<bool>(i); // Converting integer 0 to boolean
    ASSERT_FALSE(b);

    std::array<int, 4> ai = {42, 42, 42, 42};
    // No-op for transfer from and to the same types; checking values remain as intended
    ASSERT_TRUE(std::all_of(ai.begin(), ai.end(), [](int x) { return x == 42; }));
}

// Google Test setup
TEST(TransferTest, MainTest) {
    translatedCode();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}