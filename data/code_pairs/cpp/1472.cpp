#include <vector>
#include <complex>
#include <string>
#include <stdexcept>
#include <iostream>

template<typename T>
void checkMatrixSize(int nsize1, int nsize2, const std::vector<std::vector<T>>& matrix, const std::string& matname, const std::string& subname) {
    if (matrix.size() != nsize1 || (nsize1 > 0 && matrix[0].size() != nsize2)) {
        throw std::runtime_error("Matrix " + matname + " has incorrect size in " + subname);
    }
    std::cout << "Matrix " << matname << " checked successfully in " << subname << "." << std::endl;
}