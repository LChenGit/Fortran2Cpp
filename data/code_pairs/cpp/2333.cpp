#include <gtest/gtest.h>

class MyClass {
public:
    int columns;
    int hash_size;

    int updateHashSizeAndBuckets(float sparsity) {
        int num_buckets;

        hash_size = static_cast<int>(1.0 / sparsity);
        if (hash_size > columns) {
            hash_size = columns;
        }
        num_buckets = columns / hash_size + 1;

        return num_buckets;
    }
};

TEST(MyClassTest, TestCase1) {
    MyClass obj;
    obj.columns = 100;
    EXPECT_EQ(obj.updateHashSizeAndBuckets(0.05), 21); // Expectation based on the Fortran output
}

TEST(MyClassTest, TestCase2) {
    MyClass obj;
    obj.columns = 50;
    EXPECT_EQ(obj.updateHashSizeAndBuckets(0.1), 11); // Expectation based on the Fortran output
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}