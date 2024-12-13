#include <gtest/gtest.h>

#define saveTSG true

TEST(SaveTSGTest, CheckValue) {
    EXPECT_TRUE(saveTSG);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}