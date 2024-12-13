#include <gtest/gtest.h>
#include <functional>
#include <cstdlib>

int hello() {
    return 42;
}

void test(bool first) {
    static std::function<int()> x = nullptr;

    if (first) {
        if (x != nullptr) {
            std::abort();
        }
        x = hello;
    } else {
        if (x == nullptr) {
            std::abort();
        }
        int i = x();
        if (i != 42) {
            std::abort();
        }
    }
}

TEST(TestMain, TestTrue) {
    ASSERT_NO_THROW(test(true));
}

TEST(TestMain, TestFalse) {
    ASSERT_NO_THROW(test(false));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}