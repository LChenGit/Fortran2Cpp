#include <vector>
#include <array>
#include <memory>

constexpr int NTDH_MAX = 100; // Assuming the same constant for consistency

using SP = float;

struct RUNOFF {
    SP Q_INSTNT;
    SP Q_ROUTED;
    SP Q_ACCURATE;

    bool operator==(const RUNOFF& other) const {
        return Q_INSTNT == other.Q_INSTNT && Q_ROUTED == other.Q_ROUTED && Q_ACCURATE == other.Q_ACCURATE;
    }
};

std::array<SP, NTDH_MAX> FUTURE;
std::unique_ptr<std::vector<RUNOFF>> AROUTE;
std::unique_ptr<std::vector<std::vector<std::vector<RUNOFF>>>> AROUTE_3d;
RUNOFF MROUTE;