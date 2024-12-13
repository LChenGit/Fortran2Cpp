#include <gtest/gtest.h>
#include <functional>

// Define type alias for function pointers
using FuncPtr = std::function<int(int, int)>;

// Definition of the add function
int add(int a, int b) {
    return a + b;
}

// Function to set the function pointer
void set_ptr(FuncPtr& f1, FuncPtr& f2) {
    f2 = f1;
}

TEST(FunctionPointerTest, SimpleAddition) {
    FuncPtr forig = add;
    FuncPtr fset;
    set_ptr(forig, fset);

    EXPECT_EQ(forig(1, 2), 3);
    EXPECT_EQ(fset(1, 2), 3);
}

TEST(FunctionPointerTest, DifferentValues) {
    FuncPtr forig = add;
    FuncPtr fset;
    set_ptr(forig, fset);

    EXPECT_EQ(forig(5, 7), 12);
    EXPECT_EQ(fset(5, 7), 12);
}

TEST(FunctionPointerTest, NegativeValues) {
    FuncPtr forig = add;
    FuncPtr fset;
    set_ptr(forig, fset);

    EXPECT_EQ(forig(-3, 4), 1);
    EXPECT_EQ(fset(-3, 4), 1);
}

TEST(FunctionPointerTest, ZeroValues) {
    FuncPtr forig = add;
    FuncPtr fset;
    set_ptr(forig, fset);

    EXPECT_EQ(forig(0, 0), 0);
    EXPECT_EQ(fset(0, 0), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}