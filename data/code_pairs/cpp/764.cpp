#include <iostream>
#include <array>

int main() {
    std::array<float, 5> arreglo_1;
    std::array<float, 5> arreglo_2 = {1, 2, 3, 4, 5};
    std::array<std::array<int, 5>, 5> matriz;
    std::array<int, 5> arreglo_3;
    std::array<std::array<int, 6>, 5> matriz_2;
    std::array<std::array<int, 4>, 4> matriz_3;

    std::cout << "Posición 1 de arreglo_1: " << arreglo_1[0] << std::endl;
    std::cout << "Posición (2, 6) de matriz_2: " << matriz_2[2][5] << std::endl;

    // Note: Direct slice printing as in Fortran is not directly supported in C++, hence omitted

    return 0;
}