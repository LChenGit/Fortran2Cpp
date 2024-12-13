#ifndef SUPERD_I_H
#define SUPERD_I_H

#include <vector>

void superd(const std::vector<std::vector<double>>& C, 
            const std::vector<double>& EIGS, 
            int NORBS, 
            int NELECS, 
            int NUMAT, 
            const std::vector<int>& NAT);

#endif // SUPERD_I_H