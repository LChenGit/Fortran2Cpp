#include <iostream>

void s1() {
    for (int i = 1; i <= 10; ++i) {
        continue;
    }
    for (int i = 1; i <= 10; ++i) {
        break;
    }
    for (int i = 1; i <= 10; ++i) {
        continue;
        for (int j = 1; j <= 10; ++j) {
            continue;
        }
        continue;
    }
}