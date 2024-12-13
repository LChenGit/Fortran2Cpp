// File: great_ne.cpp
#include <iostream>

template<typename T>
void great_ne(T a, T b) {
    if (a > b) {
        std::cout << a << " is greater than " << b << std::endl;
    } else {
        std::cout << a << " is not greater than " << b << std::endl;
    }
}

int main() {
    great_ne(5, 3);
    great_ne(2, 4);
    great_ne(7, 7);

    return 0;
}