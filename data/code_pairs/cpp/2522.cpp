#ifndef VAR_SYS_PARAMETER_HPP
#define VAR_SYS_PARAMETER_HPP

#include <stdexcept>

class VarSysParameter {
private:
    static constexpr const char* pp_kind = "NCPP";
    bool isRootRank;
    bool isTestRank;
    int testRank = 1;
    bool isParallelTest;

public:
    VarSysParameter() {
#ifdef _ParallelTest_
        isParallelTest = true;
#else
        isParallelTest = false;
#endif
    }

    void setDispSwitch(int myrank, int nprocs);

    // Getters for testing purposes
    bool getIsRootRank() const { return isRootRank; }
    bool getIsTestRank() const { return isTestRank; }
    static const char* getPPKind() { return pp_kind; }
};

#endif // VAR_SYS_PARAMETER_HPP