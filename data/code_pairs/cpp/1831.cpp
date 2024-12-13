#ifndef DERI2_I_H
#define DERI2_I_H

#include <vector>

using DOUBLE = double;  // Assuming DOUBLE is equivalent to 'double'

class Deri2_I {
public:
    static void deri2(int minear, std::vector<std::vector<DOUBLE>>& f, 
                      const std::vector<std::vector<DOUBLE>>& fd,
                      std::vector<std::vector<DOUBLE>>& fci, int ninear, int nvar, 
                      std::vector<DOUBLE>& grad, DOUBLE throld, 
                      const std::vector<DOUBLE>& diag, const std::vector<DOUBLE>& scalar);
};

#endif // DERI2_I_H