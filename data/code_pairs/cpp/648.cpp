#include <vector>

namespace mecid_I {

class XYArray {
private:
    std::vector<std::vector<std::vector<std::vector<double>>>> data;

public:
    XYArray(size_t dim1, size_t dim2, size_t dim3, size_t dim4);
    double& at(size_t i, size_t j, size_t k, size_t l);
    const double& at(size_t i, size_t j, size_t k, size_t l) const;
};

void mecid(const std::vector<double>& EIGS, double& GSE, std::vector<double>& EIGA,
           std::vector<double>& DIAG, const XYArray& XY);

} // namespace mecid_I