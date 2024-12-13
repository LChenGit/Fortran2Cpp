#ifndef SUMALL3DARRAYDP_H
#define SUMALL3DARRAYDP_H

#include <cstdint> // For std::int32_t
#include <vector>  // For std::vector

class SumAll3DArrayDP {
public:
    static void sumAll3DArrayDP(const std::vector<std::vector<std::vector<double>>>& sendBuf,
                                std::vector<std::vector<std::vector<double>>>& recvBuf,
                                std::int32_t nx, std::int32_t ny, std::int32_t nz);
};

#endif // SUMALL3DARRAYDP_H