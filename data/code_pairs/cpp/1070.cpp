#include <gtest/gtest.h>
#include <cstddef>

class pr32601 {
public:
    static int* get_ptr() {
        static int x; // Making x static to extend its lifetime
        return &x;
    }
};

TEST(Pr32601Test, NullPointerTest) {
    int* t = nullptr;
    // Check if t is a null pointer
    EXPECT_EQ(t, nullptr);
}

TEST(Pr32601Test, GetPtrTest) {
    int* ptr = pr32601::get_ptr();
    // Check if the returned pointer is not null
    EXPECT_NE(ptr, nullptr);
    // Optionally, check the value pointed to by ptr (if it's known and initialized)
    *ptr = 5; // Assign a value
    EXPECT_EQ(*ptr, 5); // Check if the value is as expected
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}