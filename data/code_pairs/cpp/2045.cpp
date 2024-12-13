#include <vector>
#include <cmath>
#include <gtest/gtest.h>

class PrimeNumber {
public:
    void sieve_of_eratosthenes(int n, std::vector<bool>& table) {
        table.clear();
        table.resize(n + 1, true); // C++ vectors are 0-indexed, so we need n+1 elements
        table[0] = false; // Adjusting for 0-indexing. In Fortran, arrays are 1-indexed.
        table[1] = false; // Mark 1 as not prime explicitly.

        for (int i = 2; i <= n; ++i) {
            if (table[i]) {
                for (int j = i * 2; j <= n; j += i) {
                    table[j] = false;
                }
            }
        }
    }
};

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= std::sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

TEST(PrimeNumberTest, HandlesUpToTwenty) {
    PrimeNumber prime;
    std::vector<bool> primes;
    for (int n = 2; n <= 20; n += 6) {
        prime.sieve_of_eratosthenes(n, primes);
        for (int i = 2; i <= n; ++i) {
            EXPECT_EQ(primes[i], isPrime(i));
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}