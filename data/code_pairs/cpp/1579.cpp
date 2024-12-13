#include <cmath>

class PARAMETERS {
public:
    // Constants (equivalent to Fortran parameters)
    static constexpr float d2r = std::asin(1.0f) / 90.0f;
    static constexpr float mu = 40e09f;
    static constexpr float moment = 5.593e22f;

    // Variables
    float al1, al2, aw1, aw2;

    // More constants
    static constexpr float alpha = 2.0f / 3.0f;
    static constexpr float depth = 10.0f;
    static constexpr float dip = 9.0f;
    static constexpr float length = 250.0f;
    static constexpr float rake = 78.0f * d2r;
    static constexpr float strike = (180.0f - 193.0f) * d2r;

    // Constructor
    PARAMETERS() {
        start_parameters();
    }

    // Member function (equivalent to Fortran subroutine)
    void start_parameters() {
        al2 = length / 2.0f;
        al1 = -al2;
        aw1 = -150.0f;
        aw2 = 0.0f;
    }
};