#include <iostream>
#include <complex>
#include <string>

int main() {
    float var_real = 3.141517f;
    int var_int = 6;
    std::complex<float> var_cplx(2, -4);
    bool var_log = true;
    char var_char = 'a';
    std::string mnsj = "Bienvenidos al curso de Fortran de PROTECO!";

    std::cout << var_real << std::endl;
    std::cout << var_int << std::endl;
    std::cout << var_cplx << std::endl;
    std::cout << std::boolalpha << var_log << std::endl;
    std::cout << var_char << std::endl;
    std::cout << mnsj << std::endl;

    return 0;
}