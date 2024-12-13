module precision
    implicit none
    integer, parameter :: dp = selected_real_kind(15, 307) ! Double precision
    type fitlookuptable
        integer :: fittype
        integer :: fitparm
    end type fitlookuptable
    real(dp), parameter :: Yr = 31557600.0_dp
    real(dp), parameter :: Rsun = 696265000.0_dp
    real(dp), parameter :: Mearth = 5.97219e24_dp
    real(dp), parameter :: day = 86400.0_dp
    real(dp), parameter :: PI = 3.141592653589793_dp
    real(dp), parameter :: Gr = 6.6719842229637e-11_dp
    real(dp), parameter :: K2 = 2.959122082855911e-04_dp
    real(dp), parameter :: Msun = 1.9891e30_dp
    real(dp), parameter :: AU = 1.4959787e11_dp
    real(dp), parameter :: MU = Msun
    real(dp), parameter :: TU = day
    real(dp), parameter :: LU = AU
end module precision