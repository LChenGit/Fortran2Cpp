#include <iostream>

void clawloop();

int main() {
    clawloop();
    return 0;
}

void clawloop() {
    int i, j, k;
    const int iend = 2;
    const int jend = 4;
    const int kend = 2;

    for (i = 0; i <= iend; ++i) {
        if (i == 0) {
            std::cout << "First iteration of i " << i << '/' << j << '/' << k << std::endl;
        }
        for (j = 0; j <= jend; ++j) {
            for (k = 0; k <= kend; ++k) {
                std::cout << "First loop body: " << i << '/' << j << '/' << k << std::endl;
            }
        }

        for (j = 2; j <= jend; ++j) {
            for (k = 0; k <= kend; ++k) {
                std::cout << "Second loop body: " << i << '/' << j << '/' << k << std::endl;
            }
        }

        for (j = 0; j <= jend; ++j) {
            std::cout << "ALONE J LOOP" << std::endl;
        }
    }
}