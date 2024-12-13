module arg_nut
  implicit none

  integer, parameter :: xi = selected_real_kind(15)
  real(kind=xi), parameter :: pi = 4.0_xi * atan(1.0_xi)

  real(kind=xi), parameter :: t2000 = 51544.5_xi
  real(kind=xi), parameter :: Nbr_days_in_Century = 36525.0_xi

  real(kind=xi), parameter :: phil = 134.96340251_xi * pi / 180.0_xi
  real(kind=xi), parameter :: phils = 357.52910918_xi * pi / 180.0_xi
  real(kind=xi), parameter :: phiF = 93.27209062_xi * pi / 180.0_xi
  real(kind=xi), parameter :: phiD = 297.85019547_xi * pi / 180.0_xi
  real(kind=xi), parameter :: phiomega = 125.04455501_xi * pi / 180.0_xi

  real(kind=xi), parameter :: sigmal = 1717915923.2178_xi / 3600.0_xi * pi / 180.0_xi
  real(kind=xi), parameter :: sigmals = 129596581.0481_xi / 3600.0_xi * pi / 180.0_xi
  real(kind=xi), parameter :: sigmaF = 1739527262.8478_xi / 3600.0_xi * pi / 180.0_xi
  real(kind=xi), parameter :: sigmaD = 1602961601.2090_xi / 3600.0_xi * pi / 180.0_xi
  real(kind=xi), parameter :: sigmaomega = -6962890.5431_xi / 3600.0_xi * pi / 180.0_xi
end module arg_nut