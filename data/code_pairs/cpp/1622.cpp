#include <cstdlib> // For abort()

int main() {
    int x[13];
    for (int i = 0; i <= 12; ++i) {
        x[i] = i;
    }

    int* z = x;

    for (int i = 0; i <= 12; ++i) {
        if (x[i] != i || z[i] != i) {
            abort();
        }
    }

    return 0;
}