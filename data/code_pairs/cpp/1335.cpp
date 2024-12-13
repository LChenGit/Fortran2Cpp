#include <iostream>
#include <vector>
#include <algorithm>

struct type1 {
    int i1;
};

namespace bar {
    void sub1(type1& x, std::vector<int>& y) {
        y.assign(x.i1, 1);
    }

    void sub2(type1& u, std::vector<int>& v) {
        v.assign(u.i1, 2);
    }
}

namespace foobar {
    void sub3(type1& s, std::vector<int>& t) {
        t.assign(s.i1, 3);
    }
}

int main() {
    type1 z;
    std::vector<int> j(3, 0);
    
    z.i1 = 3;
    bar::sub1(z, j);
    z.i1 = 2;
    bar::sub2(z, j);
    z.i1 = 1;
    foobar::sub3(z, j);

    if (j == std::vector<int>({3, 2, 1})) {
        std::cout << "Test Passed." << std::endl;
    } else {
        std::cout << "Test Failed." << std::endl;
        return 1;
    }

    return 0;
}