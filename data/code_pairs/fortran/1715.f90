module ModTime
    use, intrinsic :: iso_fortran_env, only: real64
    implicit none

    real(real64) :: tSimulation = 0.0_real64
    integer :: iTimeArray(7) = 0
    real(real64) :: CurrentTime, EndTime, StartTime, VernalTime
    real(real64) :: PauseTime
    real(real64) :: utime
    integer :: iJulianDay, iDay
    integer :: iStep = 1

    integer, parameter :: iYear_   = 1
    integer, parameter :: iMonth_  = 2
    integer, parameter :: iDay_    = 3
    integer, parameter :: iHour_   = 4
    integer, parameter :: iMinute_ = 5
    integer, parameter :: iSecond_ = 6

end module ModTime