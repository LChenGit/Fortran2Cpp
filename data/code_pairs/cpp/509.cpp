#include <iostream>

void output_value(int i) {
    if (i == 1) {
        std::cout << 1 << std::endl;
    } else if (i == 2) {
        std::cout << 2 << std::endl;
    } else {
        std::cout << 3 << std::endl;
    }
}

int main() {
    output_value(1);
    output_value(2);
    output_value(3);
    return 0;
}