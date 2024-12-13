#include <iostream>
#include <array>
#include <gtest/gtest.h>

// Function to print the array
void bar(const std::array<int, 10>& a, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

// Function to reverse the array
std::array<int, 10> reverseArray(const std::array<int, 10>& a, int n) {
    std::array<int, 10> a_reversed;
    for (int i = 0; i < n; ++i) {
        a_reversed[i] = a[n - 1 - i];
    }
    return a_reversed;
}

// Unit test to verify the correctness of the array reversal
TEST(BarFunctionTest, ReversedArrayOutput) {
    const int n = 10;
    std::array<int, n> a;
    
    // Initialize the array
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }

    // Create a reversed copy of the array
    std::array<int, n> a_reversed = reverseArray(a, n);

    // Expected reversed array
    std::array<int, n> expected_reversed = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    // Check if the reversed array matches the expected array
    ASSERT_EQ(a_reversed, expected_reversed);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}