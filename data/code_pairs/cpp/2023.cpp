#include <iostream>

int factorial(int n) {
    if (n == 0) return 1; // Adding base case for n=0
    int fact = 1;
    for (int i = 2; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}