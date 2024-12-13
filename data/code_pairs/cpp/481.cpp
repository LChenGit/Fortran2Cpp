#include <mutex>

// Declare the increment function
void increment(int& sharedVar);

// Global mutex for demonstration purposes
std::mutex mtx;

// Function definition
void increment(int& sharedVar) {
    std::lock_guard<std::mutex> lock(mtx);
    sharedVar += 1;
}