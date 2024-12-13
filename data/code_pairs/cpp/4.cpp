#include <iostream>
#include <vector>

int main() {
    const int num_nodes = 4; // Simulating 4 processes/nodes
    const int N = 20;
    std::vector<int> a(N);

    // Simulate process IDs (ranks)
    for (int me = 1; me <= num_nodes; ++me) {
        // Initialize array based on "process rank"
        for (int i = 0; i < N; ++i) {
            a[i] = (i + 1) * me; // +1 to match Fortran 1-indexing in logic
        }

        // Simulate fetching values as if from different "nodes"
        int n1 = a[9]; // Equivalent to a(10) in Fortran
        int n2 = a[9]; // Reusing for demonstration, in real scenario, values could be from different nodes
        int n3 = a[9];

        // Print the results
        std::cout << "Simulated me,n1,n2,n3=" << me << "," << n1 << "," << n2 << "," << n3 << std::endl;
    }

    return 0;
}