#include <iostream>

void allocate_and_set(int*& ptr, int value) {
    ptr = new int(value);
}

int main() {
    int* p = nullptr;
    allocate_and_set(p, 5);
    std::cout << "Value pointed by p: " << *p << std::endl;
    delete p;
    return 0;
}