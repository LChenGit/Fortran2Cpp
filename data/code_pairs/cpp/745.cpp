#include <iostream>
#include <vector>

namespace mytypes {
    int get_i() {
        return 13;
    }
}

int main() {
    std::vector<int> x(mytypes::get_i());
    std::cout << x.size() << std::endl;
    return 0;
}