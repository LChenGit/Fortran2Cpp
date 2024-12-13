#include <iostream>

class powsq_I {
public:
    virtual void powsq(int n, int& result) = 0; // Pure virtual function
    virtual ~powsq_I() {} // Virtual destructor
};

class powsq_Impl : public powsq_I {
public:
    void powsq(int n, int& result) override { // Implementation of powsq
        result = n * n;
    }
};

int main() {
    powsq_Impl powsqInstance; // Create an instance of the implementation
    int number = 4; // Input number
    int squared; // Variable to hold the result
    
    powsqInstance.powsq(number, squared); // Call the powsq function
    std::cout << "Square of " << number << " is " << squared << std::endl; // Display the result
    
    return 0; // Return success
}