module constants
    implicit none

    logical, parameter :: BIN_OUTPUT = .false.
    integer, parameter :: FFT_TYPE = 1
    double precision, parameter :: PI = 3.141592653589793d0
    double precision, parameter :: DAY = 3600.d0*24.d0
    double precision, parameter :: WEEK = 7d0*DAY
    double precision, parameter :: MONTH = 30*DAY
    double precision, parameter :: YEAR = 365*DAY
    
    ! Variables
    integer :: FAULT_TYPE = 0
    integer :: SOLVER_TYPE = 0
    
end module constants