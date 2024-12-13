#include <vector>
#include <cstddef> // For size_t

void rpn2_cons_update_manifold(size_t meqn, size_t maux, int idir, int iface,
                               const std::vector<double>& q,
                               const std::vector<double>& auxvec_center,
                               const std::vector<double>& auxvec_edge,
                               std::vector<double>& flux);

void rpn2_cons_update_zero(size_t meqn, size_t maux, int idir, int iface,
                           const std::vector<double>& q,
                           const std::vector<double>& auxvec_center,
                           const std::vector<double>& auxvec_edge,
                           std::vector<double>& flux);