#include <iostream>
#include <vector>
#include <limits>

int main() {
    const int num_procs = 4; // Assuming a total of 4 processes
    int boss = 3; // Identifying the "boss" process

    for (int me = 1; me <= num_procs; ++me) {
        std::vector<int> resc(3, std::numeric_limits<int>::min()), tmp(3);

        // Initialize resc based on the condition
        if (me == boss) {
            std::fill(resc.begin(), resc.end(), 0);
        } else {
            std::fill(resc.begin(), resc.end(), -std::numeric_limits<int>::max());
        }

        if (me != boss) {
            // Simulating receiving, modifying, and sending the array for non-boss processes
            tmp = resc;
            tmp[0] += 1;
            tmp[1] += 1;
            // Simulate sending the modified array back
            resc = tmp;
        } else {
            // Simulating the boss process updating its array based on "received" updates
            for (int i = 0; i < 100 * (num_procs - 1); ++i) {
                resc[0] -= 1;
                resc[2] += 1;
            }
        }

        // Printing the results for this simulation
        std::cout << "Process " << me << ": ";
        for (const auto& val : resc) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}