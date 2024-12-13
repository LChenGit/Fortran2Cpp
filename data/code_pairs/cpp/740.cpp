#include <gtest/gtest.h>
#include <string>

std::string test(int alen) {
    std::string result = "test";
    return result;
}

std::string test2(int alen) {
    std::string result = "test";
    return result;
}

TEST(TestSuite, TestFunction) {
    ASSERT_EQ(test(2).length(), 4);
    ASSERT_EQ(test(2), "test");
}

TEST(TestSuite, Test2Function) {
    ASSERT_EQ(test2(2).length(), 4);
    ASSERT_EQ(test2(2), "test");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}