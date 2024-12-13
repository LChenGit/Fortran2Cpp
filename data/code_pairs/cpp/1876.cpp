#include <iostream>

void foo() {
    int p, k;
    int sum_p = 0, sum_k = 0;
    
    for(p = 1; p <= 5; ++p) {
        sum_p += p;
    }
    for(k = 2; k <= 6; ++k) {
        sum_k += k;
    }

    std::cout << "Sum of p: " << sum_p << std::endl;
    std::cout << "Sum of k: " << sum_k << std::endl;
}

int main() {
    foo();
    return 0;
}