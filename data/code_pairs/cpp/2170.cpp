#include <iostream>
#include <cassert>

class Reduce {
public:
    void operator()(double& theta, double& phi) {
        reduce(theta, phi);
    }

private:
    void reduce(double& theta, double& phi) {
        // Example logic: increment theta and phi by 1
        theta += 1.0;
        phi += 1.0;
    }
};

void test_reduce() {
    Reduce reducer;

    // Test case 1
    double theta = 1.0;
    double phi = 2.0;
    reducer(theta, phi);
    assert(theta == 2.0 && phi == 3.0);
    std::cout << "Test case 1 passed" << std::endl;

    // Additional test cases can be added here
}

int main() {
    test_reduce();
    return 0;
}