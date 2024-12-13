#ifndef CONSTANTS_H
#define CONSTANTS_H

class Constants {
public:
    static constexpr bool BIN_OUTPUT = false;
    static constexpr int FFT_TYPE = 1;
    static constexpr double PI = 3.141592653589793;
    static constexpr double DAY = 3600.0*24.0;
    static constexpr double WEEK = 7.0*DAY;
    static constexpr double MONTH = 30*DAY;
    static constexpr double YEAR = 365*DAY;
    
    // Variables
    static int FAULT_TYPE;
    static int SOLVER_TYPE;
};

// Static member definitions
int Constants::FAULT_TYPE = 0;
int Constants::SOLVER_TYPE = 0;

#endif // CONSTANTS_H