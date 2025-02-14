// File: identity_function_tests.cpp

#include <iostream>
#include <functional>

using namespace std;

int main() {
    // Identity lambda function
    auto identityLambda = [](const int& x) { return x; };

    // Test cases for the identity lambda
    assert(identityLambda(5) == 5);
    assert(identityLambda(-3) == -3);
    assert(identityLambda(0) == 0);

    cout << "All tests for identity function passed." << endl;

    return 0;
}