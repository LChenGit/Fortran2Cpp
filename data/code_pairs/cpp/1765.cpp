#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include <vector>

using Matrix = std::vector<std::vector<double>>;

Matrix matmul(const Matrix& a, const Matrix& b);
Matrix transpose(const Matrix& m);
bool approxEqual(const Matrix& a, const Matrix& b, double eps = 1e-9);
void mass_matrix(Matrix& MM1);

#endif // MATRIX_OPERATIONS_H