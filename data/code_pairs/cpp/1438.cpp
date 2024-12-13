#include <iostream>
#include <cmath>
#include <cassert>

int64_t calculateSumOfPrimes() {
    int64_t sum = 2; 
    bool isPrime;

    for (int64_t n = 3; n < 2000000; n += 2) { 
        isPrime = true;
        for (int64_t i = 3; i <= static_cast<int64_t>(std::sqrt(n)); i += 2) { 
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            sum += n;
        }
    }
    
    return sum;
}

int main() {
    int64_t result = calculateSumOfPrimes();
    std::cout << "solution: " << result << std::endl;
    
    // Test
    assert(result == 142913828922);
    std::cout << "Test passed. Result is correct." << std::endl;

    return 0;
}