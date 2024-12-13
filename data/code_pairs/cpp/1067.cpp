#include <iostream>

int calculate_sum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    return sum;
}

int main() {
    int sum = calculate_sum(10);
    std::cout << "The sum is " << sum << std::endl;
    return 0;
}