#include <iostream>

// Forward declarations
void work(int i, int j);
void a6_wrong();

// Definition of work
void work(int i, int j) {
    std::cout << "WORK called with I=" << i << " and J=" << j << std::endl;
}

// Definition of a6_wrong
void a6_wrong() {
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            work(i, j);
        }
    }
}

int main() {
    a6_wrong(); // Call the function
    return 0;
}