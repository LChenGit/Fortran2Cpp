// meshfem3d_models_broadcast.cpp
#include <iostream>
#include <string>
#include <array>

namespace MESHFEM3D_MODELS_BROADCAST__genmod {

    void MESHFEM3D_MODELS_BROADCAST(int MYRANK, const std::array<int, 3>& NSPEC,
                                    int MIN_ATTENUATION_PERIOD, int MAX_ATTENUATION_PERIOD,
                                    double R80, double R220, double R670, double RCMB, double RICB,
                                    const std::string& LOCAL_PATH) {
        std::cout << "Function MESHFEM3D_MODELS_BROADCAST called with MYRANK: " << MYRANK << std::endl
                  << "NSPEC: " << NSPEC[0] << " " << NSPEC[1] << " " << NSPEC[2] << std::endl
                  << "Period Range: " << MIN_ATTENUATION_PERIOD << " - " << MAX_ATTENUATION_PERIOD << std::endl
                  << "R Values: " << R80 << " " << R220 << " " << R670 << " " << RCMB << " " << RICB << std::endl
                  << "Local Path: " << LOCAL_PATH << std::endl;
    }

}