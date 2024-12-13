#include <iostream>

int compute_sum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    return sum;
}

int main() {
    std::cout << "The sum is " << compute_sum(10) << std::endl;
    return 0;
}