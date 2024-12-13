#include <vector>
#include <iostream>

namespace m {

struct t {
};

class t2 {
public:
    t2() : value(0) {}
    void setValue(int val) { value = val; }
    int getValue() const { return value; }
    ~t2() { fini(); }

private:
    int value;
    void fini() {
        std::cout << "t2::fini() called, value: " << value << std::endl;
    }
};

} // namespace m

void foo(std::vector<m::t>& x, m::t& y, std::vector<m::t2>& aa, m::t2& bb) {
    bb.setValue(42);
}

int main() {
    std::vector<m::t> x;
    m::t y;
    std::vector<m::t2> aa;
    m::t2 bb;

    std::cout << "Before calling foo, bb's value is: " << bb.getValue() << std::endl;
    foo(x, y, aa, bb);
    std::cout << "After calling foo, bb's value is: " << bb.getValue() << std::endl;

    return 0;
}