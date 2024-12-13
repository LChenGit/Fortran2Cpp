#include <iostream>
#include <vector>

void sub1();
void sub2();

int main() {
    sub1(); // Call sub1 from main
    return 0;
}

void sub1() {
    std::vector<float> a(10);

    sub2();  // Call sub2
    std::cout << "sub1 was called" << std::endl;
}

void sub2() {
    std::vector<int> a(10);

    std::cout << "sub2 was called" << std::endl;
}