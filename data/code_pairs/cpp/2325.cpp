// test_mod.cpp
#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>

struct t1 {
    std::string str;
    t1(const char* s) : str(s) {}
};

struct t2 {
    int tab;
    std::shared_ptr<std::vector<t1>> fp;
};

struct t3 {
    int tab;
    std::shared_ptr<t2> as;
};

std::vector<std::shared_ptr<t3>> as_typ;
std::vector<std::string> *p = nullptr;

void as_set_alias(int i) {
    as_typ.resize(2);
    as_typ[0] = std::make_shared<t3>();
    as_typ[0]->as = std::make_shared<t2>();
    as_typ[0]->as->fp = std::make_shared<std::vector<t1>>(std::initializer_list<t1>{{"abcdefgh"}, {"ijklmnop"}});

    p = new std::vector<std::string>;
    for (const auto& item : *(as_typ[i-1]->as->fp)) {
        p->push_back(item.str);
    }
}

TEST(TestMod, AsSetAlias) {
    as_set_alias(1);

    std::vector<std::string> expected = {"abcdefgh", "ijklmnop"};
    ASSERT_TRUE(*p == expected);

    delete p;
    as_typ.clear();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}