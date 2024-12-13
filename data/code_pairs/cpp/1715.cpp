#ifndef MODTIME_HPP
#define MODTIME_HPP

#include <array>

namespace ModTime {
    double tSimulation = 0.0;
    std::array<int, 7> iTimeArray{}; // Initialized with zeros

    double CurrentTime, EndTime, StartTime, VernalTime;
    double PauseTime;
    double utime; // Assuming it should be initialized to zero (not guaranteed in C++ without explicit initialization)
    int iJulianDay, iDay; // Assuming these should be initialized to zero for the test
    int iStep = 1;

    constexpr int iYear_   = 1;
    constexpr int iMonth_  = 2;
    constexpr int iDay_    = 3;
    constexpr int iHour_   = 4;
    constexpr int iMinute_ = 5;
    constexpr int iSecond_ = 6;
}

#endif // MODTIME_HPP