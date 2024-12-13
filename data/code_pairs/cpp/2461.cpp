#ifndef COM_VAR_H
#define COM_VAR_H

#include <string>
#include <complex>
#include <vector>

class COM_VAR {
public:
    float RHO = 1.225f;
    float G = 9.81f;
    float Depth = 100.0f;
    float XEFF = 1.0f, YEFF = 2.0f, ZEFF = 3.0f;
    std::string MESHFILE = "mesh.dat";
    int LFILE = 10, NP = 1000, NFA = 2000;
    int IMX = 10, IXX = 20, NSYMY = 30;
    float ZER = 0.0f;
    int Indiq_solver = 1;
    int Sav_potential = 1;
    // Add more variables as needed

    float calculateSomething() {
        return RHO + G + Depth + XEFF + YEFF + ZEFF;
    }
};

#endif // COM_VAR_H