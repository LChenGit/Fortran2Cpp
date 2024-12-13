#include <gtest/gtest.h>
#include <string>

class StringManipulation {
public:
    static std::pair<std::string, char> manipulateAndTest(const std::string& b) {
        std::string c = b.substr(1, 6);
        char a = c[0];
        return {c, a};
    }
};

TEST(StringManipulationTest, SubstringAndCharacterExtraction) {
    std::string b = "HIFROMPGI";
    auto [c, a] = StringManipulation::manipulateAndTest(b);

    EXPECT_EQ(c, "IFROMP");
    EXPECT_EQ(a, 'I');
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}