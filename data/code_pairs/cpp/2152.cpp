// example.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

double evaluate(int n) {
    double sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    return sum;
}

int myMutation(double pm) {
    double r = static_cast<double>(rand()) / RAND_MAX;
    return r < pm ? 1 : 0;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for randomness

    double pm = 0.5; // Example mutation probability.
    int n = 10;      // Example population size for evaluation.

    double evalResult = evaluate(n);
    std::cout << "Evaluate function result: " << evalResult << std::endl;
    if (evalResult == 55.0) {
        std::cout << "Evaluate function test passed." << std::endl;
    } else {
        std::cout << "Evaluate function test failed." << std::endl;
    }

    int mutationResult = myMutation(pm);
    std::cout << "Mutation function result (0 or 1): " << mutationResult << std::endl;
    if (mutationResult == 0 || mutationResult == 1) {
        std::cout << "Mutation function test passed." << std::endl;
    } else {
        std::cout << "Mutation function test failed." << std::endl;
    }

    return 0;
}