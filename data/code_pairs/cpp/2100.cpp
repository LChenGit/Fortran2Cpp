#include <cstdint>

class Fibonacci {
public:
    static int64_t fib_naive(int n) {
        if (n < 2) return n;
        return fib_naive(n - 1) + fib_naive(n - 2);
    }

    static int64_t fib_iter(int n) {
        int64_t a = 0, b = 1, tmp;
        for (int i = 1; i <= n; ++i) {
            tmp = b;
            b = a + b;
            a = tmp;
        }
        return a;
    }
};