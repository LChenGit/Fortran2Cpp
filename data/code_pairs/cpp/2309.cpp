#include <iostream>
#include <array>
#include <string>

struct Summary {
    float VAR_RESIDUL;
    float LOGP_SIMULN;
    float JUMP_TAKEN;
    float QOBS_MEAN;
    float QSIM_MEAN;
    float QOBS_CVAR;
    float QSIM_CVAR;
    float QOBS_LAG1;
    float QSIM_LAG1;
    float RAW_RMSE;
    float LOG_RMSE;
    float NASH_SUTT;
    float NUM_RMSE;
    float NUM_FUNCS;
    float NUM_JACOBIAN;
    float NUMSUB_ACCEPT;
    float NUMSUB_REJECT;
    float NUMSUB_NOCONV;
    int MAXNUM_ITERNS;
    std::array<float, 20> NUMSUB_PROB;
    std::string ERR_MESSAGE;
};

int main() {
    Summary MSTATS;
    // Example initialization for testing
    MSTATS.VAR_RESIDUL = 1.234f;
    MSTATS.LOGP_SIMULN = 2.345f;
    for(int i = 0; i < 20; ++i) {
        MSTATS.NUMSUB_PROB[i] = i + 1.0f;
    }
    MSTATS.ERR_MESSAGE = "Test error message";

    // Example output for verification
    std::cout << "VAR_RESIDUL: " << MSTATS.VAR_RESIDUL << std::endl;
    std::cout << "LOGP_SIMULN: " << MSTATS.LOGP_SIMULN << std::endl;
    std::cout << "NUMSUB_PROB: ";
    for(const auto& val : MSTATS.NUMSUB_PROB) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    std::cout << "ERR_MESSAGE: " << MSTATS.ERR_MESSAGE << std::endl;

    return 0;
}