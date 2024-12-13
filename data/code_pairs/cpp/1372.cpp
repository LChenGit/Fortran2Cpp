#ifndef RD3DMODL_GENMOD_H
#define RD3DMODL_GENMOD_H

#include <string>
#include <vector>

namespace RD3DMODL__genmod {

void RD3DMODL(const std::string& FILENAME, int& IERROR, const int NMODKERN, const int NHORPAR,
              const std::vector<int>& ITYPHPAR, const std::vector<int>& IHORPAR,
              const std::vector<int>& LMAXHOR, const std::vector<int>& NCOEFHOR,
              const std::vector<std::vector<float>>& XLASPL, const std::vector<std::vector<float>>& XLOSPL,
              const std::vector<std::vector<float>>& XRASPL, const std::vector<std::vector<int>>& IXLSPL,
              const std::vector<std::vector<float>>& COEF, const std::vector<std::string>& HSPLFILE,
              const std::string& REFMODEL, const std::string& KERNSTRI, const std::vector<std::string>& DESCKERN);

} // namespace RD3DMODL__genmod

#endif // RD3DMODL_GENMOD_H