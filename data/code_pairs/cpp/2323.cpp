#include <vector>
#include <iostream>

void SUBTRACT_MEAN_3D(const std::vector<std::vector<std::vector<float>>>& A_IN,
                      int MAXX_IN, int MAXY_IN, int MAXZ_IN,
                      int NX, int NY, int NZ,
                      float BADDATA,
                      int MAXX_OUT, int MAXY_OUT, int MAXZ_OUT,
                      std::vector<std::vector<std::vector<float>>>& A_OUT) {
    float SUM = 0.0;
    int COUNT = 0;

    for (int IZ = 0; IZ < NZ; ++IZ) {
        for (int IY = 0; IY < NY; ++IY) {
            for (int IX = 0; IX < NX; ++IX) {
                if (A_IN[IX][IY][IZ] != BADDATA) {
                    SUM += A_IN[IX][IY][IZ];
                    COUNT++;
                }
            }
        }
    }

    float MEAN = 0.0;
    if (COUNT > 0) {
        MEAN = SUM / COUNT;
    }

    for (int IZ = 0; IZ < NZ; ++IZ) {
        for (int IY = 0; IY < NY; ++IY) {
            for (int IX = 0; IX < NX; ++IX) {
                if (A_IN[IX][IY][IZ] != BADDATA) {
                    A_OUT[IX][IY][IZ] = A_IN[IX][IY][IZ] - MEAN;
                } else {
                    A_OUT[IX][IY][IZ] = BADDATA;
                }
            }
        }
    }
}

int main() {
    const int NX = 3, NY = 3, NZ = 3;
    const float BADDATA = -999.0;
    std::vector<std::vector<std::vector<float>>> A_IN(NX, std::vector<std::vector<float>>(NY, std::vector<float>(NZ)));
    std::vector<std::vector<std::vector<float>>> A_OUT(NX, std::vector<std::vector<float>>(NY, std::vector<float>(NZ)));

    // Initialize with some test data
    for (int ix = 0; ix < NX; ++ix) {
        for (int iy = 0; iy < NY; ++iy) {
            for (int iz = 0; iz < NZ; ++iz) {
                A_IN[ix][iy][iz] = static_cast<float>(ix + iy + iz);
            }
        }
    }

    SUBTRACT_MEAN_3D(A_IN, NX, NY, NZ, NX, NY, NZ, BADDATA, NX, NY, NZ, A_OUT);

    // Output the result for verification
    for (int ix = 0; ix < NX; ++ix) {
        for (int iy = 0; iy < NY; ++iy) {
            for (int iz = 0; iz < NZ; ++iz) {
                std::cout << A_OUT[ix][iy][iz] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}