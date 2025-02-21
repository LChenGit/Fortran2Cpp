#include <iostream>

namespace ExampleModule {
    int exampleFunction() {
        return 42;
    }

    void exampleSubroutine() {
        std::cout << "This is an example subroutine." << std::endl;
    }
}

int main() {
    // Call the subroutine
    ExampleModule::exampleSubroutine();

    // Call the function and print the result
    int x = ExampleModule::exampleFunction();
    std::cout << "The function returned: " << x << std::endl;

    return 0;
}