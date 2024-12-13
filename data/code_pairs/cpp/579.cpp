#include <iostream>
#include <chrono>

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    // Your code here (This can be any operation you wish to measure the CPU time for)
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "CPU Time: " << elapsed.count() << " seconds" << std::endl;
    return 0;
}