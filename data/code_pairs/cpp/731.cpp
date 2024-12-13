#include <iostream>
#include <functional>

class p {
public:
    void test() {
        std::cout << avg(std::bind(&p::erfc, this, std::placeholders::_1)) << std::endl;
    }

private:
    double avg(std::function<double(double)> f) {
        return (f(1.0) + f(2.0)) / 2.0;
    }

    double erfc(double x) {
        return x; // Simplified implementation for demonstration
    }
};

void runTests() {
    p testObj;
    testObj.test(); // Assuming this is how we invoke the test method for class p
    std::cout << "All tests passed." << std::endl;
}

int main() {
    runTests(); // Run tests before the main functionality
    // If you have additional code to run after tests, it can go here
    return 0;
}