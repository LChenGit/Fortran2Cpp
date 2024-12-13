#include <iostream>
#include <vector>
#include <memory>
#include <cassert>

class Block {
public:
    std::vector<float> fields;

    Block() = default;

    Block(float value) : fields(1, value) {} // Initialize with 1 element of value
};

class List {
public:
    std::shared_ptr<Block> B;

    List() = default;

    List(const Block& block) : B(std::make_shared<Block>(block)) {} // Copy constructor
};

class Domain {
public:
    std::vector<List> L;

    Domain() : L(2) {} // Initialize with 2 List elements
};

int main() {
    Domain d;
    Block b1(5.0); // Initialize Block with 5.0

    d.L[1].B = std::make_shared<Block>(b1); // Assign shared_ptr<Block> in List

    // Assert to validate the test
    assert(d.L[1].B->fields[0] == 5.0); // Check if the value is as expected

    std::cout << "Test Passed" << std::endl; // Print test passed

    return 0;
}