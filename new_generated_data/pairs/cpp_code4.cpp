#include <iostream>
#include <omp.h>
#include <cassert>

int main() {
    const int n = 4;
    double shared_array[n];

    // Initialize array to 0.0
    for (int i = 0; i < n; ++i) {
        shared_array[i] = 0.0;
    }

    #pragma omp parallel num_threads(2)
    {
        if (omp_get_thread_num() == 0) {
            // Thread 0 modifies the array
            for (int i = 0; i < n; ++i) {
                shared_array[i] = 1.0;
            }

            // Synchronize memory
            #pragma omp flush
        }

        // All threads wait
        #pragma omp barrier

        // Verify array values
        for (int i = 0; i < n; ++i) {
            assert(shared_array[i] == 1.0);
        }
    }

    std::cout << "All tests passed in C++!" << std::endl;

    return 0;
}