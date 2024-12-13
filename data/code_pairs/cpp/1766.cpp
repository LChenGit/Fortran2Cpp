#include <iostream>
#include <cstdint>

namespace CREATE_REGIONS_MESH__genmod {

void CREATE_REGIONS_MESH(int32_t IREGION_CODE, int32_t NSPEC,
                         int32_t NGLOB_THEOR, int32_t NPOINTOT,
                         int32_t NEX_PER_PROC_XI, int32_t NEX_PER_PROC_ETA,
                         int32_t NSPEC2DMAX_XMIN_XMAX, int32_t NSPEC2DMAX_YMIN_YMAX,
                         int32_t NSPEC2D_BOTTOM, int32_t NSPEC2D_TOP,
                         int32_t OFFSET_PROC_XI, int32_t OFFSET_PROC_ETA,
                         int32_t IPASS) {
    std::cout << "Function CREATE_REGIONS_MESH called with parameters:" << std::endl;
    std::cout << "IREGION_CODE: " << IREGION_CODE << std::endl;
    std::cout << "NSPEC: " << NSPEC << std::endl;
    std::cout << "NGLOB_THEOR: " << NGLOB_THEOR << std::endl;
    std::cout << "IPASS: " << IPASS << std::endl;
}

} // namespace CREATE_REGIONS_MESH__genmod