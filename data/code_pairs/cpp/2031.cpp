// m_irjc_matrix_lag_translated.hpp
#include <vector>
#include <cassert>
#include <iostream>

struct irjc_square_matrix {
    int neqns;
    int nttbr;
    int ndeg;
    std::vector<int> irow;
    std::vector<int> jcol;
    std::vector<std::vector<double>> val;
};

struct irjc_mn_matrix {
    int nrows;
    int ncols;
    int nttbr;
    int ndeg;
    std::vector<int> irow;
    std::vector<int> jcol;
    std::vector<std::vector<double>> val;
};

// main.cpp
#include "m_irjc_matrix_lag_translated.hpp"

int main() {
    irjc_square_matrix square_matrix;
    
    // Initialize some data
    square_matrix.neqns = 3;
    square_matrix.nttbr = 2;
    square_matrix.ndeg = 1;
    square_matrix.irow = {1, 2, 3};
    square_matrix.jcol = {1, 2, 3};
    square_matrix.val = {{1.0, 1.0, 1.0}, {2.0, 2.0, 2.0}, {3.0, 3.0, 3.0}};

    // Assertions to verify correctness
    assert(square_matrix.neqns == 3);
    assert(square_matrix.nttbr == 2);
    assert(square_matrix.ndeg == 1);
    for(int i = 0; i < square_matrix.neqns; ++i) {
        assert(square_matrix.irow[i] == i + 1);
        assert(square_matrix.jcol[i] == i + 1);
        for(int j = 0; j < square_matrix.neqns; ++j) {
            assert(square_matrix.val[i][j] == i + 1);
        }
    }

    std::cout << "All tests passed." << std::endl;

    return 0;
}