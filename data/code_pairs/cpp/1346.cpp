#ifndef BUFRQEL_MOD_H
#define BUFRQEL_MOD_H

#include <string>
#include <vector>

namespace BUFRQEL_mod {
    void BUFRQEL(const std::string& STRING, bool CMPRES, int LASTEL, int LASBIT, int N,
                 int& NEXBIT, int& SCALE, int& WIDTH, int& REFVAL, char& FORMAT,
                 std::vector<int>& DESCR, int& NLOG, int& IRC);
}

#endif // BUFRQEL_MOD_H