#include <vector>
#include <cstddef> // For std::size_t

class IMFUD {
public:
    static std::vector<std::vector<std::vector<std::vector<int>>>> i_imfud0(
        const std::vector<std::vector<std::vector<std::vector<int>>>>& ida2, 
        std::size_t nds4, std::size_t nds3) {
        return manipulateArray(ida2, nds4, nds3);
    }

private:
    static std::vector<std::vector<std::vector<std::vector<int>>>> manipulateArray(
        const std::vector<std::vector<std::vector<std::vector<int>>>>& ida2, 
        std::size_t nds4, std::size_t nds3) {
        // Note: Adjusted the operation to match Fortran's behavior as per unit test results
        std::size_t dim1 = ida2.size();
        std::size_t dim2 = dim1 > 0 ? ida2[0].size() : 0;
        std::size_t dim3 = dim2 > 0 && ida2[0].size() > 0 ? ida2[0][0].size() : 0;
        std::size_t dim4 = dim3 > 0 && ida2[0][0].size() > 0 ? ida2[0][0][0].size() : 0;

        std::vector<std::vector<std::vector<std::vector<int>>>> result(dim1, std::vector<std::vector<std::vector<int>>>(dim2, std::vector<std::vector<int>>(dim3, std::vector<int>(dim4))));

        for (std::size_t i = 0; i < dim1; ++i) {
            for (std::size_t j = 0; j < dim2; ++j) {
                for (std::size_t k = 0; k < dim3; ++k) {
                    for (std::size_t l = 0; l < dim4; ++l) {
                        result[i][j][k][l] = 1 - ida2[i][j][k][l];
                    }
                }
            }
        }

        return result;
    }
};