#include <iostream>
#include <cmath>

void realim(float* a, float* b, int m, int n) {
    float im;
    float modul;
    float phase;
    float rl;

    for (int k = 0; k < n; ++k) {
        for (int j = 0; j < m; ++j) {
            modul = a[j + k * m];
            phase = b[j + k * m];
            rl = modul * cos(phase);
            im = modul * sin(phase);
            a[j + k * m] = rl;
            b[j + k * m] = im;
        }
    }
}

void printArray(float* arr, int m, int n, const std::string& name) {
    std::cout << name << ":" << std::endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << arr[i + j * m] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    const int m = 2;
    const int n = 2;
    float a[m * n] = { 1.0, 3.0, 2.0, 4.0 };
    float b[m * n] = { 0.0, 1.0, 0.5, 1.5 };

    std::cout << "Initial arrays:" << std::endl;
    printArray(a, m, n, "a");
    printArray(b, m, n, "b");

    realim(a, b, m, n);

    std::cout << "Modified arrays:" << std::endl;
    printArray(a, m, n, "a");
    printArray(b, m, n, "b");

    return 0;
}