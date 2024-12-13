#include <iostream>
#include <vector>

// Function prototype
void sub(std::vector<int>& a, int n);

// Test function prototype
void test_sub(std::vector<int> a, int n);

int main() {
    std::vector<int> a(10), b(0), c(1); // Normal case, empty array, single-element array

    test_sub(a, 10);
    test_sub(b, 0);  // Edge case: Testing with an empty array
    test_sub(c, 1);  // Testing with a single-element array

    return 0;
}

void sub(std::vector<int>& a, int n) {
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }
}

void test_sub(std::vector<int> a, int n) {
    sub(a, n);
    if (!a.empty()) {
        std::cout << "Array after sub call:" << std::endl;
        for (int i = 0; i < a.size(); ++i) {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Empty array test case." << std::endl;
    }
}