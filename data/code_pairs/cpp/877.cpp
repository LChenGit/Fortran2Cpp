// phasefield_cpp_bc2.cpp
#include <iostream>
#include <vector>

class Array3D {
private:
    std::vector<double> data;
    int dimX, dimY, dimZ;
public:
    Array3D(int x, int y, int z) : dimX(x), dimY(y), dimZ(z), data(x * y * z, 0.0) {}

    double& operator()(int x, int y, int z) {
        // Corrected index calculation for 0-based indexing
        return data[(z * dimY + y) * dimX + x]; 
    }
};

void phasefield_cpp_bc2(int meqn, int mbc, int mx, int my, double xlower, double ylower, double dx, double dy, Array3D& q, double t, double dt, std::vector<int> intersects_bc) {
    for (int m = 0; m < meqn; ++m) {
        if (intersects_bc[0] != 0) {
            for (int ibc = 1; ibc <= mbc; ++ibc) {
                for (int j = 0; j < my + 2*mbc; ++j) {
                    q(ibc - 1, j, m) = q(0, j, m);
                }
            }
        }

        if (intersects_bc[1] != 0) {
            for (int ibc = 1; ibc <= mbc; ++ibc) {
                for (int j = 0; j < my + 2*mbc; ++j) {
                    q(mx - 1 + ibc, j, m) = q(mx - 1, j, m);
                }
            }
        }

        if (intersects_bc[2] != 0) {
            for (int jbc = 1; jbc <= mbc; ++jbc) {
                for (int i = 0; i < mx + 2*mbc; ++i) {
                    q(i, jbc - 1, m) = q(i, 0, m);
                }
            }
        }

        if (intersects_bc[3] != 0) {
            for (int jbc = 1; jbc <= mbc; ++jbc) {
                for (int i = 0; i < mx + 2*mbc; ++i) {
                    q(i, my - 1 + jbc, m) = q(i, my - 1, m);
                }
            }
        }
    }
}

int main() {
    int meqn = 2, mbc = 2, mx = 5, my = 5;
    std::vector<int> intersects_bc = {1, 1, 1, 1};
    Array3D q(mx + 2*mbc, my + 2*mbc, meqn);

    for(int m = 0; m < meqn; ++m) {
        for(int i = 0; i < mx + 2*mbc; ++i) {
            for(int j = 0; j < my + 2*mbc; ++j) {
                // Set interior values to 1
                q(i, j, m) = (i >= mbc && i < mx + mbc && j >= mbc && j < my + mbc) ? 1.0 : 0.0;
            }
        }
    }

    phasefield_cpp_bc2(meqn, mbc, mx, my, 0.0, 0.0, 1.0, 1.0, q, 0.0, 1.0, intersects_bc);

    for(int m = 0; m < meqn; ++m) {
        std::cout << "Equation: " << m << std::endl;
        for(int j = 0; j < my + 2*mbc; ++j) {
            for(int i = 0; i < mx + 2*mbc; ++i) {
                std::cout << q(i, j, m) << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}