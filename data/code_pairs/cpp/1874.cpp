// ELHEX27_TESTE.hpp
#ifndef ELHEX27_TESTE_HPP
#define ELHEX27_TESTE_HPP

#include <vector>

const int P = 2, Q = 2, W = 2, NDS = 3;

class ELHEX27_TESTE {
public:
    static void ELHEX27_TESTE_Function(int NEL, std::vector<std::vector<double>>& KE, 
                                       const std::vector<std::vector<double>>& EL_DDISP, 
                                       std::vector<std::vector<double>>& FINTE, int INC);
};

#endif // ELHEX27_TESTE_HPP

// ELHEX27_TESTE.cpp
#include "ELHEX27_TESTE.hpp"

void ELHEX27_TESTE::ELHEX27_TESTE_Function(int NEL, std::vector<std::vector<double>>& KE, 
                                           const std::vector<std::vector<double>>& EL_DDISP, 
                                           std::vector<std::vector<double>>& FINTE, int INC) {
    // Function logic here
    // For demonstration, this function will not perform any calculations.
    std::fill(FINTE.begin(), FINTE.end(), std::vector<double>(1, 0.0));
}

// main.cpp
#include "ELHEX27_TESTE.hpp"
#include <iostream>

int main() {
    int NEL = 1;
    int INC = 1;
    int dim = (P + 1) * (Q + 1) * (W + 1) * NDS;
    std::vector<std::vector<double>> KE(dim, std::vector<double>(dim, 0.0));
    std::vector<std::vector<double>> EL_DDISP(dim, std::vector<double>(1, 0.0));
    std::vector<std::vector<double>> FINTE(dim, std::vector<double>(1, 0.0));

    ELHEX27_TESTE::ELHEX27_TESTE_Function(NEL, KE, EL_DDISP, FINTE, INC);

    std::cout << "FINTE first element: " << FINTE[0][0] << std::endl;

    return 0;
}