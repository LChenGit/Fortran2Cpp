// main_operation.cpp
#include <iostream>
#include <vector>
#include <chrono>

int main() {
    std::vector<double> X(1000000000, 1.0);
    std::vector<double> Y(1000000000, 1.0);
    std::vector<double> runtimes(10);
    double meanruntimes = 0.0;

    for (int i = 0; i < 10; ++i) {
        auto start = std::chrono::high_resolution_clock::now();

        for (size_t j = 0; j < X.size(); ++j) {
            X[j] = X[j] + Y[j] + Y[j];
        }

        auto stop = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = stop - start;
        
        runtimes[i] = duration.count();
    }

    for (double time : runtimes) {
        meanruntimes += time;
    }
    meanruntimes /= 10.0;

    std::cout << "mean run time in seconds" << std::endl;
    std::cout << meanruntimes << std::endl;

    return 0;
}