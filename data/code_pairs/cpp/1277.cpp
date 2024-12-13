#include <iostream>

// Mock example to simulate functionality
class MemoryManager {
public:
    void allocateMemory(int& allocBytes, int& garbageBytes) {
        // Mock increase in allocated bytes and garbage bytes
        allocBytes += 10;
        garbageBytes += 5;
    }

    void deallocateMemory(int& allocBytes, int& garbageBytes) {
        // Mock decrease in allocated and garbage bytes
        allocBytes -= 10;
        garbageBytes -= 5;
    }
};

int main() {
    int allocBytes = 100; // Initial mock allocated bytes
    int garbageBytes = 50; // Initial mock garbage bytes

    MemoryManager manager;
    manager.allocateMemory(allocBytes, garbageBytes);
    manager.deallocateMemory(allocBytes, garbageBytes);

    std::cout << "Memory management operations completed." << std::endl;

    return 0;
}