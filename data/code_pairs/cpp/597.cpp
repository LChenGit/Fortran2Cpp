#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) {
        return 1;
    }

    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

void assertEqual(int computed, int expected, const string& message) {
    if (computed == expected) {
        cout << message << ": Success" << endl;
    } else {
        cout << message << ": Failure. Expected " << expected << " but got " << computed << endl;
    }
}

void testFactorial() {
    // Test 1
    assertEqual(factorial(5), 120, "Test 1");

    // Test 2
    assertEqual(factorial(0), 1, "Test 2");

    // Add more tests as needed
}

int main() {
    testFactorial();
    return 0;
}