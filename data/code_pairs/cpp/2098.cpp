#include <iostream>
#include <vector>

void sub(std::vector<int>& a, int n);

int main() {
    std::vector<int> a(10);
    sub(a, 10);

    for(int i = 0; i < a.size(); i++) {
        if (a[i] != i + 1) {
            std::cout << "Test failed at index: " << i << std::endl;
            return -1;
        }
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}

void sub(std::vector<int>& a, int n) {
    for(int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
}