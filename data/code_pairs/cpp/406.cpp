#include <iostream>
#include <vector>
#include <memory>

struct ttt {
    int* p = nullptr;
};

int main() {
    int a[2] = {0};
    int b[2][2] = {{0}};
    int c[4] = {0};
    int d[2] = {0};
    int e[2] = {0};
    int f[3][3] = {{0}};
    const int stride = 2;
    std::vector<ttt> arr_of_ttt(2);
    int x = 88;

    for (int i = 0; i < 2; ++i) a[i] = i + 1;
    for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) b[i][j] = i + j + 2;
    for (int i = 0; i < 4; i += 2) c[i] = i + 1;
    for (int i = 0; i < 2; ++i) d[i] = i + 1;
    for (int i = 1; i <= 2; ++i) if (i % 2 == 0) e[i-1] = i;
    for (int i = 0; i < 3; i += stride) for (int j = 0; j < 3; ++j) f[i][j] = i + j + 2;

    for (int i : a) std::cout << i << ' ';
    std::cout << '\n';
    for (auto& row : b) { for (int val : row) std::cout << val << ' '; std::cout << '\n'; }
    for (int i : c) std::cout << i << ' ';
    std::cout << '\n';
    for (int i : d) std::cout << i << ' ';
    std::cout << '\n';
    for (int i : e) std::cout << i << ' ';
    std::cout << '\n';
    for (auto& row : f) { for (int val : row) std::cout << val << ' '; std::cout << '\n'; }

    for (auto& item : arr_of_ttt) item.p = &x;
    for (auto& item : arr_of_ttt) std::cout << *(item.p) << '\n';

    return 0;
}