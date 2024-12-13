#include <gtest/gtest.h>
#include <type_traits>

struct t1 {
    int i;
};

struct ts {
    int j;
};

template<typename T, typename U>
constexpr bool same_type_as = std::is_same<T, U>::value;

template<typename T, typename U>
constexpr bool extends_type_of = std::is_base_of<U, T>::value;

TEST(TypeComparisonTests, SameTypeAs) {
    EXPECT_FALSE((same_type_as<int, t1>));
    EXPECT_FALSE((same_type_as<t1, ts>));
}

TEST(TypeComparisonTests, ExtendsTypeOf) {
    EXPECT_FALSE((extends_type_of<int, t1>));
    EXPECT_FALSE((extends_type_of<t1, ts>));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}