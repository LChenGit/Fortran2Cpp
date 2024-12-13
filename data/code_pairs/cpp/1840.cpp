#include <cstdint>
#include <iostream>

class GET_SLICE_NUMBER__genmod {
public:
    static std::int32_t GET_SLICE_NUMBER(std::int32_t ICHUNK, std::int32_t IXI, std::int32_t IETA, std::int32_t NPROC_XI, std::int32_t NPROC_ETA) {
        return (ICHUNK * NPROC_XI * NPROC_ETA) + (IXI * NPROC_ETA) + IETA;
    }
};