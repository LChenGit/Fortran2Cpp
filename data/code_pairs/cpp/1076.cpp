#include <iostream>
#include <array>

int main() {
    std::array<std::array<bool, 2>, 2> l1 = {{{false, true}, {true, false}}};
    std::array<std::array<int, 2>, 2> it = {{{1, 2}, {3, 4}}};

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (l1[i][j]) {
                it[i][j] = 0;
            }
        }
    }

    std::array<std::array<int, 2>, 2> expected = {{{1, 0}, {0, 4}}};
    bool testPassed = true;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (it[i][j] != expected[i][j]) {
                testPassed = false;
                break;
            }
        }
        if (!testPassed) break;
    }

    if (testPassed) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cerr << "Test failed." << std::endl;
        return 1;
    }

    return 0;
}