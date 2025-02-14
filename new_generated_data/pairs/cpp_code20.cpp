#include <omp.h>
#include <iostream>
#include <cassert>

int main() {
    // Set the number of threads
    omp_set_num_threads(2);

    // Declare and initialize the array
    double a2[2][3] = {0}; // 2x3 array initialized to zero
    int nerr = 0;

    #pragma omp parallel
    {
        int me = omp_get_thread_num();

        // Print thread number and array for verification
        std::cout << "Thread " << me << " initialized a2:" << std::endl;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << a2[i][j] << " ";
            }
            std::cout << std::endl;
        }

        // Check that a2 is initialized to zero
        bool aInitialized = true;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (a2[i][j] != 0.0) {
                    aInitialized = false;
                    break;
                }
            }
            if (!aInitialized) break;
        }
        assert(aInitialized && "a2 array not initialized to zero");

        // Check that thread number is valid
        assert(me >= 0 && "Invalid thread number");
    }

    // Success message
    std::cout << "All tests passed." << std::endl;

    return 0;
}