#include <gtest/gtest.h>
#include <string>

bool isStringNonEmpty(const std::string& s) {
    return !s.empty();
}

TEST(StringNonEmptyTest, NonEmptyString) {
    std::string s = "abcd";
    EXPECT_TRUE(isStringNonEmpty(s));
}

TEST(StringNonEmptyTest, EmptyString) {
    std::string s = "";
    EXPECT_FALSE(isStringNonEmpty(s));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}