#include <cassert>
#include <vector>
#include <iostream>

int main() {
    const int N = 10000;
    std::vector<int> vec(N, 1); // Initialize a vector with 10000 elements set to 1
    std::vector<int> results(N, 0); // Initialize a results vector

    // Perform a simple operation in parallel
    #pragma acc parallel loop copyin(vec[0:N]) copyout(results[0:N])
    for(int i = 0; i < N; ++i) {
        results[i] = vec[i] * 2; // Each element is multiplied by 2
    }

    // Verify the results
    for(int i = 0; i < N; ++i) {
        assert(results[i] == 2); // Each element in results should now be 2
    }

    std::cout << "All tests passed." << std::endl;

    return 0;
}