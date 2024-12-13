#include <iostream>

void great_ne(int var1, int var2) {
    if (var1 != var2) {
        std::cout << var1 << " and " << var2 << " are not equal." << std::endl;
    }
}

int main() {
    int jj1 = 1, a1 = 2, bb1 = 3, y1 = 4, f1 = 5;

    great_ne(jj1, a1);
    great_ne(bb1, y1);
    great_ne(y1, f1);

    return 0;
}