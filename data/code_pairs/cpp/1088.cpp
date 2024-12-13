#ifndef MODEL_DEFN_H
#define MODEL_DEFN_H

#include <array>
#include <string>

// Constants
const std::string FUSE_version = "FUSE 1.0";
const bool FUSE_enabled = true;
const int NDEC = 9;
const int NTDH_MAX = 500;

// DESC type
struct DESC {
    std::string MCOMPONENT;
    DESC() : MCOMPONENT(16, ' ') {}
};

// UMODEL type
struct UMODEL {
    int MODIX;
    std::string MNAME;
    int iRFERR, iARCH1, iARCH2, iQSURF, iQPERC, iESOIL, iQINTF, iQ_TDH, iSNOWM;
    UMODEL() : MNAME(256, ' '), MODIX(0), iRFERR(0), iARCH1(0), iARCH2(0), iQSURF(0), iQPERC(0), iESOIL(0), iQINTF(0), iQ_TDH(0), iSNOWM(0) {}
};

// SNAMES type
struct SNAMES {
    int iSNAME;
};

// FNAMES type
struct FNAMES {
    std::string FNAME;
    FNAMES() : FNAME(16, ' ') {}
};

// Global variables / equivalent module variables
std::array<DESC, 2> LIST_RFERR;
std::array<DESC, 3> LIST_ARCH1;
std::array<DESC, 4> LIST_ARCH2;
std::array<DESC, 3> LIST_QSURF;
std::array<DESC, 3> LIST_QPERC;
std::array<DESC, 2> LIST_ESOIL;
std::array<DESC, 2> LIST_QINTF;
std::array<DESC, 2> LIST_Q_TDH;
std::array<DESC, 2> LIST_SNOWM;

std::array<UMODEL, 5000> AMODL;
UMODEL SMODL;

std::array<SNAMES, 7> CSTATE;
int NSTATE = 0;

std::array<FNAMES, 50> C_FLUX;
int N_FLUX = 0;

#endif // MODEL_DEFN_H