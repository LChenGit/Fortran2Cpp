#include <iostream>

namespace foo {
    struct t {
        int i;
        t(int val) : i(val) {}  // Constructor to allow initialization
    };

    int operator*(const t& lhs, const t& rhs) {
        return lhs.i * rhs.i;
    }
}

namespace bar {
    struct t2 {
        int i;
        t2(int val) : i(val) {}  // Constructor to allow initialization
    };

    bool operator>(const t2& lhs, const t2& rhs) {
        return lhs.i > rhs.i;
    }
}

int main() {
    foo::t i(1), j(2);
    bar::t2 k(1), l(2);

    std::cout << "i*j = " << i * j << std::endl;
    std::cout << "k > l = " << (k > l ? "true" : "false") << std::endl;

    return 0;
}