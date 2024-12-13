module precision_config
  implicit none
  integer, parameter :: wp = selected_real_kind(15, 307)
  real(wp), parameter :: pi = 4.0_wp * atan(1.0_wp)
  real(wp), parameter :: f_actual = -9.02462E-6_wp
end module precision_config