#include <cstdint>
#include <cstring>
#include <array>

namespace NWTC_Base {

    constexpr std::size_t BITS_IN_ADDR = sizeof(std::intptr_t) * 8;
    constexpr std::size_t ErrMsgLen = 1024;
    
    constexpr std::intptr_t ChanLen = 10;
    constexpr std::intptr_t NWTC_Verbose = 10;
    constexpr std::intptr_t NWTC_VerboseLevel = 5;

    constexpr std::intptr_t ErrID_None = 0;
    constexpr std::intptr_t ErrID_Info = 1;
    constexpr std::intptr_t ErrID_Warn = 2;
    constexpr std::intptr_t ErrID_Severe = 3;
    constexpr std::intptr_t ErrID_Fatal = 4;

    std::intptr_t AbortErrLev = ErrID_Fatal;
    
    constexpr std::intptr_t NWTC_MAX_DLL_PROC = 3;

    struct DLL_Type {
        std::intptr_t FileAddr{};
        void* FileAddrX{nullptr};
        std::array<void(*)(), NWTC_MAX_DLL_PROC> ProcAddr{};
        char FileName[ErrMsgLen]{};
        std::array<char[ErrMsgLen], NWTC_MAX_DLL_PROC> ProcName{};

        DLL_Type() {
            std::memset(FileName, 0, ErrMsgLen);
            for (auto& name : ProcName) {
                std::memset(name, 0, ErrMsgLen);
            }
        }
    };
}