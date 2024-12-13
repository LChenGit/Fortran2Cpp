// rotatd_I.h
#include <vector>
#include <numeric>

class rotatd_I {
public:
    void rotatd(int IP, int JP, int IA, int IB, int JA, int JB, int NI, int NJ,
                const std::vector<double>& CI, const std::vector<double>& CJ,
                std::vector<double>& W, int LMW, double& ENUC);
};