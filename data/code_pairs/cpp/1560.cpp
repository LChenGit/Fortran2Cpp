#include <iostream>

struct t {
    char c;
    t(char ch) : c(ch) {}
};

char initializeAndTest(char input) {
    t typeInstance(input);
    return typeInstance.c;
}

int main() {
    char x = initializeAndTest('a');
    std::cout << "Value of x: " << x << std::endl;
    return 0;
}