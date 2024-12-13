#include <iostream>
#include <vector>

// Function prototypes
void foo();
void bar();

int main() {
    bar(); // Calling bar which in turn calls foo
    return 0;
}

void foo() {
    // Initialize the array 'a' with 3 elements all set to 1
    std::vector<int> a(3, 1); // This line initializes 'a' correctly

    // Since we're essentially multiplying a 3x1 matrix of all 1's with a 1x3 matrix of all 1's,
    // the result is a 3x3 matrix of all 1's.
    std::vector<std::vector<int>> result(3, std::vector<int>(3, 1));

    // Print the result
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void bar() {
    foo();
}