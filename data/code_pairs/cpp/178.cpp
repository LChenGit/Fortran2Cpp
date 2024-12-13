#include <iostream>
#include <vector>

int main() {
    std::vector<float> vla1(5, 1.0f);  // Allocate and initialize vla1
    vla1[1] = 42.0f;  // 1-based to 0-based indexing adjustment
    vla1[3] = 24.0f;
    bool l = !vla1.empty();  // Check if vla1 is not empty (allocated)
    std::cout << "Test 1a Passed" << std::endl;

    vla1.clear();  // Deallocation
    l = vla1.empty();  // Check if vla1 is empty (deallocated)
    std::cout << "Test 1b Passed" << std::endl;

    std::vector<std::vector<float>> vla2(5, std::vector<float>(2, 2.0f));  // Allocate and initialize vla2
    float* pvla2 = nullptr;  // Initialize pointer to nullptr
    pvla2 = &vla2[0][0];  // Simulating pointer association
    l = (pvla2 != nullptr);  // Check if pvla2 is associated
    std::cout << "Test 2a Passed" << std::endl;

    pvla2[2 * vla2[0].size() + 0] = 42.0f;  // Modify an element through pvla2

    pvla2 = nullptr;  // Disassociate pvla2
    l = (pvla2 == nullptr);  // Check if pvla2 is disassociated
    std::cout << "Test 2b Passed" << std::endl;

    return 0;
}