#include <iostream>

void print_array(int hx[6][6]) {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            std::cout.width(3); // Align for better readability
            std::cout << hx[j][i] << ' ';
        }
        std::cout << std::endl;
    }
}

int main() {
    int hx[6][6];
    int ps, e2;

    for (ps = 0; ps < 6; ++ps) {
        for (e2 = 0; e2 < 6; ++e2) {
            hx[e2][ps] = 0;
            if (ps >= 4 && e2 >= 4) {
                hx[e2][ps] = 99; // Using 99 for a clear test case
            }
        }
    }

    // Test output
    print_array(hx);

    return 0;
}