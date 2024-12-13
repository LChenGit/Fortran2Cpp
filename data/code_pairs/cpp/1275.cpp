#include <vector>

struct Block_Energy {
    std::vector<float> q_ns;
    std::vector<float> q_na;
    std::vector<float> dbt;
    std::vector<float> wind;
    std::vector<float> ea;
    std::vector<float> press;
    std::vector<float> mu;
    float alphamu;
    float beta;
    float gmma;
    float smooth_param;
    float lvp;
    float rb;
    float rho;

    static constexpr float evap_coeff = 1.5e-9f;
    static constexpr float pf = 0.640f;
    static constexpr float pi = 3.14159f;
    static constexpr float rfac = 304.8f;
};