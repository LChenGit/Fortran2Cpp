#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Function declaration
void fc3d_clawpack5_fort_tag4refinement(int mx, int my, int mz, int mbc,
                                        int meqn, double xlower, double ylower, double zlower,
                                        double dx, double dy, double dz, int blockno,
                                        double* q, double tag_threshold, int init_flag, int& tag_patch);

// Function definition
void fc3d_clawpack5_fort_tag4refinement(int mx, int my, int mz, int mbc,
                                        int meqn, double xlower, double ylower, double zlower,
                                        double dx, double dy, double dz, int blockno,
                                        double* q, double tag_threshold, int init_flag, int& tag_patch) {

    tag_patch = 0;

    int mq = 0; // In C++, array indexes start at 0

    // Initialize qmin and qmax
    double qmin = q[(mq * (mx + 2 * mbc) * (my + 2 * mbc) * (mz + 2 * mbc))];
    double qmax = qmin;

    for (int k = 0; k < mz + 2 * mbc; ++k) {
        for (int j = 0; j < my + 2 * mbc; ++j) {
            for (int i = 0; i < mx + 2 * mbc; ++i) {
                double qval = q[mq + i + j * (mx + 2 * mbc) + k * (mx + 2 * mbc) * (my + 2 * mbc)];
                qmin = std::min(qval, qmin);
                qmax = std::max(qval, qmax);

                if (qmax - qmin > tag_threshold) {
                    tag_patch = 1;
                    return;
                }
            }
        }
    }
}

int main() {
    // Initialize parameters
    int mx = 4, my = 4, mz = 4, mbc = 1, meqn = 1, blockno = 0, tag_patch = 0, init_flag = 0;
    double xlower = 0.0, ylower = 0.0, zlower = 0.0, dx = 1.0, dy = 1.0, dz = 1.0, tag_threshold = 0.5;

    // Allocate and initialize array q
    std::vector<double> q((meqn * (mx + 2 * mbc) * (my + 2 * mbc) * (mz + 2 * mbc)), 0.0);
    // Index adjustment for C++ 0-based indexing
    q[(1 - mbc) + (2 - mbc) * (mx + 2 * mbc) + (2 - mbc) * (mx + 2 * mbc) * (my + 2 * mbc)] = 1.0;  // Set a value that will trigger the tag

    // Call the function
    fc3d_clawpack5_fort_tag4refinement(mx, my, mz, mbc, meqn, xlower, ylower, zlower, dx, dy, dz, blockno, q.data(), tag_threshold, init_flag, tag_patch);

    // Print the result
    std::cout << "Tag Patch: " << tag_patch << std::endl;

    return 0;
}