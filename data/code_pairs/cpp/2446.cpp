#include <iostream>
#include <vector>
#include <cassert>

void map(std::vector<int>& a, std::vector<int>& b, int n) {
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }

    for (int i = 0; i < n; ++i) {
        b[i] = i + 1;
    }
}

void check(const std::vector<int>& a, const std::vector<int>& b, int n) {
    for (int i = 0; i < n; ++i) {
        assert(a[i] == b[i]);
    }
}

void run_main_program() {
    const int n = 20;
    std::vector<int> a(n, 0), b(n, 0);

    map(a, b, n);

    check(a, b, n);
}

int main() {
    run_main_program();
    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}