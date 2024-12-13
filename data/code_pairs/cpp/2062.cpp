// KVECANS__genmod.h
#ifndef KVECANS_GENMOD_H
#define KVECANS_GENMOD_H

#include <vector>

namespace KVECANS__genmod {

void KVECANS(int NCPX, int P, const std::vector<double>& U_KNOT, double UK, std::vector<double>& UB);

} // namespace KVECANS__genmod

#endif // KVECANS_GENMOD_H