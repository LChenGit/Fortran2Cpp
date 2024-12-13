#include <iostream>

constexpr int __SINGLE_PRECISION = 1;
constexpr int __DOUBLE_PRECISION = 2;
constexpr int __2D               = 7;
constexpr int __3D               = 8;
constexpr int __SFIELD           = 9; // Not explicitly used but defined for completeness

template<int Kind, int MeshDim>
class PpmMgProlong {
public:
    static void execute() {
        if(Kind == __SINGLE_PRECISION && MeshDim == __2D) {
            std::cout << "Single Precision 2D functionality called" << std::endl;
        } else if(Kind == __DOUBLE_PRECISION && MeshDim == __2D) {
            std::cout << "Double Precision 2D functionality called" << std::endl;
        } else if(Kind == __SINGLE_PRECISION && MeshDim == __3D) {
            std::cout << "Single Precision 3D functionality called" << std::endl;
        } else if(Kind == __DOUBLE_PRECISION && MeshDim == __3D) {
            std::cout << "Double Precision 3D functionality called" << std::endl;
        }
    }
};

int main() {
    PpmMgProlong<__SINGLE_PRECISION, __2D>::execute();
    PpmMgProlong<__DOUBLE_PRECISION, __2D>::execute();
    PpmMgProlong<__SINGLE_PRECISION, __3D>::execute();
    PpmMgProlong<__DOUBLE_PRECISION, __3D>::execute();
    
    return 0;
}