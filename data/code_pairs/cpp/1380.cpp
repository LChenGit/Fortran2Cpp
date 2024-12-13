// File: DLARFB_Genmod.hpp
#ifndef DLARFB_GENMOD_HPP
#define DLARFB_GENMOD_HPP

class DLARFB_Genmod {
public:
  static void DLARFB(char SIDE, char TRANS, char DIRECT, char STOREV,
                     int M, int N, int K, double* V, int LDV,
                     double* T, int LDT, double* C, int LDC,
                     double* WORK, int LDWORK);
};

#endif // DLARFB_GENMOD_HPP