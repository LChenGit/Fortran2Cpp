// test_a1_d1.cpp
#include <iostream>
#include <vector>

int main() {
    const int me = 1; // Simulating process ID as 1 for this example
    int nerr = 0;
    std::vector<int> a(7);
    std::vector<std::vector<int>> b(10, std::vector<int>(3, -1234));

    for (int i = 0; i < 7; ++i) {
        a[i] = (i + 1) * me;
    }

    if (me == 1) {
        for (int i = 0; i < 7; ++i) {
            b[i][0] = a[i];
        }
    }

    for (int j = 0; j < 3; ++j) {
        for (int i = 0; i < 10; ++i) {
            if (me == 1 && j == 0 && i < 7) {
                if (b[i][j] != (i + 1) * 2) {
                    nerr++;
                }
            } else {
                if (b[i][j] != -1234) {
                    nerr++;
                }
            }
        }
    }

    if (nerr == 0) {
        std::cout << "result[" << me << "] OK" << std::endl;
    } else {
        std::cout << "result[" << me << "] number of NGs: " << nerr << std::endl;
    }

    return 0;
}