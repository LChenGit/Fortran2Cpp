#include <iostream>
#include <array>

void loop_program(std::array<int, 8>& a) {
    for (int i = 0; i < a.size(); ++i) {
        a[i] = i + 1;
    }
}

int main() {
    std::array<int, 8> a;
    loop_program(a);
    std::cout << "PASS" << std::endl;
    return 0;
}