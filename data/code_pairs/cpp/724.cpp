#include <iostream>
#include <memory>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>

class PsbBaseSparseMat {
public:
    std::vector<int> irp;

    PsbBaseSparseMat(int size = 0) : irp(size) {}

    PsbBaseSparseMat(const PsbBaseSparseMat& other) : irp(other.irp) {}
    
    PsbBaseSparseMat& operator=(const PsbBaseSparseMat& other) {
        if (this != &other) {
            this->irp = other.irp;
        }
        return *this;
    }
};

void runTests() {
    PsbBaseSparseMat acsr(4);
    acsr.irp = {1, 3, 4, 5};

    std::unique_ptr<PsbBaseSparseMat> a(new PsbBaseSparseMat(acsr));
    a->irp = std::move(acsr.irp);

    std::vector<int> expectedValues = {1, 3, 4, 5};

    // Test 1: Check if the array a->irp has the expected values
    assert(std::equal(a->irp.begin(), a->irp.end(), expectedValues.begin()) && "Test 1 Failed: a->irp contents differ from expected.");

    std::cout << "All tests passed successfully." << std::endl;
}

int main() {
    runTests();
    return 0;
}