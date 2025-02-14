// C++ translation of the Fortran code

#include <iostream>

namespace UtilBlockData {
    // Common block /IUTLCM/
    static int iu[100] = {
        1, 1, 10, 10, 50, 2, 1, 1, 1, 8000,
        0, 1, 1000, 1000,  // Remaining elements are initialized to 0
    };

    // Common block /VCTSEQ/
    static int nq = 1;
    static double qx[50] = {0.0};
    static double qy[50] = {0.0};
    static int nf = 1;
    static int if_array[25] = {1};

    // Common block /PLTCM/
    static int jx = 0;
    static int jy = 0;
}

// Empty subroutine
void UTILBD() {
    // This subroutine does nothing
}

// Function to initialize common blocks
void InitializeCommonBlocks() {
    // Common block /IUTLCM/ is already initialized
    // Common block /VCTSEQ/ is already initialized
    // Common block /PLTCM/ is already initialized
    // No additional initialization needed as static variables are set at declaration
}

int main() {
    // Initialize common blocks
    InitializeCommonBlocks();

    // Call empty subroutine
    UTILBD();

    // Output the results
    std::cout << "C++ implementation completed successfully." << std::endl;
    std::cout << "IU: ";
    for (int i = 0; i < 14; ++i) {
        std::cout << UtilBlockData::iu[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "NQ: " << UtilBlockData::nq << std::endl;
    std::cout << "QX[0]: " << UtilBlockData::qx[0] << std::endl;
    std::cout << "QY[0]: " << UtilBlockData::qy[0] << std::endl;
    std::cout << "NF: " << UtilBlockData::nf << std::endl;
    std::cout << "IF_ARRAY[0]: " << UtilBlockData::if_array[0] << std::endl;
    std::cout << "JX: " << UtilBlockData::jx << std::endl;
    std::cout << "JY: " << UtilBlockData::jy << std::endl;

    return 0;
}