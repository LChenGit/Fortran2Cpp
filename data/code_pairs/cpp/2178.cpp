// Save this as clawpack46.cpp
#include <iostream>
#include <vector>
#include <cmath>

void clawpack46_tag4refinement(int mx, int my, int mbc, int meqn,
                               double xlower, double ylower, double dx, double dy,
                               int blockno, std::vector<std::vector<std::vector<double>>>& q,
                               double refine_threshold, int init_flag, int& tag_for_refinement) {
    tag_for_refinement = 0;

    for (int mq = 0; mq < meqn; ++mq) {
        for (int i = 1; i <= mx; ++i) { // Corrected loop index starting at 1
            for (int j = 1; j <= my; ++j) { // Correct loop index starting at 1
                double qx = (q[i + 1][j][mq] - q[i - 1][j][mq]) / (2 * dx);
                double qy = (q[i][j + 1][mq] - q[i][j - 1][mq]) / (2 * dy);
                if (std::abs(qx) > refine_threshold || std::abs(qy) > refine_threshold) {
                    tag_for_refinement = 1;
                    return;
                }
            }
        }
    }
}

int main() {
    int mx = 4;
    int my = 4;
    int mbc = 1;
    int meqn = 1;
    double xlower = 0.0;
    double ylower = 0.0;
    double dx = 1.0;
    double dy = 1.0;
    int blockno = 1;
    double refine_threshold = 0.5;
    int init_flag = 1;
    int tag_for_refinement;

    std::vector<std::vector<std::vector<double>>> q(mx + 2 * mbc, std::vector<std::vector<double>>(my + 2 * mbc, std::vector<double>(meqn, 0.0)));

    // Initialize q with a value that should trigger refinement
    q[2][2][0] = 1.0;

    clawpack46_tag4refinement(mx, my, mbc, meqn, xlower, ylower, dx, dy, blockno, q, refine_threshold, init_flag, tag_for_refinement);

    std::cout << "Tag for refinement: " << tag_for_refinement << std::endl;

    return 0;
}