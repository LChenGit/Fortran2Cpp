#include <iostream>

// Declaration of the LmdVmixMod class
class LmdVmixMod {
public:
    // Method that mimics the Fortran function
    double doSomething(double x) {
        return x * 2.0;
    }
};

int main() {
    LmdVmixMod obj; // Instantiate LmdVmixMod
    double result = obj.doSomething(5.0); // Use the method

    // Output the result
    std::cout << "Result of doSomething(5.0): " << result << std::endl;

    return 0;
}