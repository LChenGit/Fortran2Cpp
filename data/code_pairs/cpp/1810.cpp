#include <iostream>
#include <string>

struct tt {
    int a;
    double b;
    std::string c;

    tt(int a, double b, std::string c) : a(a), b(b), c(c) {}
};

int main() {
    tt a(1, 20.0, "ccc");
    std::cout << a.a << " " << a.b << " " << a.c << std::endl;
    return 0;
}