#include <cstdlib> // For std::abort()
#include <iostream> // For std::cout

class m {
public:
    int f() {
        value = 42; // Initialize the value
        sub(); // Call the nested subroutine
        if (value == 1) value += 1; // Modify the value based on the condition
        return value; // Return the modified value
    }

private:
    int value; // Member variable to hold the "return" value
    
    void sub() { // Nested subroutine
        if (value == 42) value -= 41; // Modify 'value' based on the condition
    }
};

// Simple unit test function
void test_f() {
    m module; // Create an instance of the class 'm'
    if (module.f() == 2) { // Check the return value of the function 'f()'
        std::cout << "Test passed." << std::endl; // Print test passed message
    } else {
        std::cout << "Test failed." << std::endl; // Print test failed message
    }
}

int main() {
    test_f(); // Call the test function
    return 0; // Return success
}