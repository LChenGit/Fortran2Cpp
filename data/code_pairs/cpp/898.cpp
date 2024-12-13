// Coll_gammaN_exclPi.h
#ifndef COLL_GAMMAN_EXCLPI_H
#define COLL_GAMMAN_EXCLPI_H

#include <vector>
#include "particleDefinition.h"
#include "eN_eventDefinition.h"

class Coll_gammaN_exclPi {
public:
    static void DoColl_gammaN_exclPi(const electronNucleon_event& eNev, int ExclPiCharge, bool& FlagOK, std::vector<particle>& OutPart, double& XS_Tot);
};

#endif // COLL_GAMMAN_EXCLPI_H