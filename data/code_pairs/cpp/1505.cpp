// File: GRTRML.cpp
#include <iostream>
#include <string>
#include <algorithm>

void GRTRML(std::string& STRING, int& L) {
    STRING = "/dev/tty";
    L = std::min(static_cast<int>(STRING.length()), 8);
}

int main() {
    std::string STRING;
    int L;

    GRTRML(STRING, L);

    std::cout << STRING << std::endl;
    std::cout << L << std::endl;

    return 0;
}