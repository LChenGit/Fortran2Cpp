#include <iostream>
#include <vector>

class M {
public:
    static int a, b;
};

int M::a = 0; // Assuming these values are appropriately initialized based on the context or another part of the program.
int M::b = 0;

void f1(std::vector<int>& c, std::vector<int>& d) {
    for (int i = 0; i < 64; ++i) {
        d[i] = M::a;
        M::a += c[i];
    }
}

int main() {
    std::vector<int> c(64, 1); // Initialize vector c with 64 elements, each of 1
    std::vector<int> d(64); // Initialize vector d with 64 elements, default to 0

    f1(c, d);

    for (int i = 0; i < 64; ++i) {
        std::cout << "d(" << i + 1 << ") = " << d[i] << std::endl;
    }
    std::cout << "Final value of a: " << M::a << std::endl;

    return 0;
}