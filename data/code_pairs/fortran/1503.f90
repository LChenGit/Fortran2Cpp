module globvars
  implicit none

  integer, parameter :: dp = kind(0.d0)
  real(dp), parameter :: eps_dp = epsilon(1.0_dp)
  character(*), parameter :: dp_format = "(es25.16e3)"
  character(*), parameter :: dp_format_raw = "es25.16e3"

  real(dp), parameter :: pi = 4.0_dp * atan(1.0_dp)
  real(dp), parameter :: tau = 2.0_dp * pi
  real(dp), parameter :: e = exp(1.0_dp)
  complex(dp), parameter :: j = (0.0_dp, 1.0_dp)

end module globvars