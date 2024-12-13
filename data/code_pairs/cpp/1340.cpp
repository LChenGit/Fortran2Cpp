#include <string>

struct Injection {
    // Double precision variables
    double RCM_injection = 0.0;
    double ZCM_injection = 0.0;
    double Rwidth_injection = 0.0;
    double Zwidth_injection = 0.0;
    double XCM_injection = 0.0;
    double YCM_injection = 0.0;
    double Xwidth_injection = 0.0;
    double Ywidth_injection = 0.0;
    double alpha0 = 0.0;
    double beta0 = 0.0;
    double V0 = 0.0;
    double devalpha = 0.0;
    double devbeta = 0.0;
    double devV = 0.0;

    // Character variables
    std::string inject_type_pos = "pointlike";
    std::string inject_type_vel = "stationary";

    // Logical variables
    bool inject_coord_cart = false;
    bool inject_coord_cyl = false;
    bool inject_coord_tilt = false;
    bool rand_seed = true;
};