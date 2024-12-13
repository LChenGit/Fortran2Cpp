#include <iostream>
#include <omp.h>
#include <cassert>

// Define the MY_TYPE structure
struct MY_TYPE {
    int X;
};

// Function prototype for FOO
void FOO(MY_TYPE var);

// Unit test function for FOO
void test_FOO() {
    MY_TYPE var;
    var.X = -1;  // Initialize var.X to -1

    FOO(var);  // Call the FOO function

    // Check the value of var.X
    if (var.X != -1) {
        std::cerr << "Test Failed: var.X is not -1" << std::endl;
    } else {
        std::cout << "Test Passed" << std::endl;
    }
}

// Function definition for FOO
void FOO(MY_TYPE var) {
    // OpenMP task with firstprivate(var)
    #pragma omp task firstprivate(var)
    {
        var.X = 1;  // Modify var.X inside the task
    }

    #pragma omp taskwait  // Wait for all tasks to complete
}

// Main function to run the test
int main() {
    test_FOO();
    return 0;
}