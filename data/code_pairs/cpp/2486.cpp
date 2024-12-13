#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

int main() {
    const int N = 10;
    std::vector<int> random_array(N), a(N);
    int ans_val = 0, sa = 0, result = 0;

    // Initialize random seed
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Fill the random_array with random values
    for (int i = 0; i < N; ++i) {
        random_array[i] = static_cast<int>((static_cast<float>(std::rand()) / RAND_MAX) * 10000);
        a[i] = random_array[i];
    }

    // Calculate ans_val and sa using bitwise OR operation
    for (int i = 0; i < N; ++i) {
        ans_val |= random_array[i];
        sa |= a[i];
    }

    // Compare sa and ans_val
    result = (sa == ans_val) ? 0 : -1;

    if (result == 0) {
        std::cout << "PASS" << std::endl;
    } else {
        std::cout << "ERROR" << std::endl;
        return 1;
    }

    return 0;
}