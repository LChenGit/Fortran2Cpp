#include <iostream>
#include <memory>
#include <vector>

struct ParticleType {
    std::shared_ptr<std::vector<int>> p;
};

int main() {
    auto t = std::make_shared<std::vector<ParticleType>>(1);
    (*t)[0].p = std::make_shared<std::vector<int>>(0); // Allocating an empty vector

    bool f = (*t)[0].p != nullptr; // Checking if the pointer is not null

    std::cout << (f ? "Test passed: t(i).p is associated." : "Test failed: t(i).p is not associated.") << std::endl;

    return 0;
}