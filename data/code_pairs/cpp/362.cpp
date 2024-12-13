#ifndef SMCONSTANTS_H
#define SMCONSTANTS_H

struct SMConstants {
    static constexpr int DOUBLE_DIGITS = 15;
    static constexpr int SINGLE_DIGITS = 6;
    
    using RP = double;
    using SP = float;
    using CP = double;

    SMConstants() = delete;
};

#endif // SMCONSTANTS_H