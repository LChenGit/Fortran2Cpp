#include <vector>
#include <iostream>

class SHAPEFUNCEAS__genmod {
public:
    static void SHAPEFUNCEAS(int NEL, int NNODES, int NDS, int NELEMS, int NSHPL, int P, int Q, int W,
                             double XII, double ETAI, double ZETAI,
                             std::vector<double>& R, std::vector<std::vector<double>>& DRDX, double& DETJ,
                             std::vector<std::vector<double>>& JAC, const std::vector<double>& UDISP,
                             const std::vector<std::vector<double>>& POINTS, const std::vector<std::vector<int>>& IEN) {
        std::cout << "SHAPEFUNCEAS called with NEL: " << NEL << std::endl;
    }
};