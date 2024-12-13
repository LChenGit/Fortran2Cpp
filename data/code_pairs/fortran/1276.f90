! cmn_tp_mod.f90
module cmn_tp_mod
  implicit none

  ! Assuming the precision is defined somewhere or using a default one.
  integer, parameter :: wp = selected_real_kind(15, 307)

  type :: dis
    real(wp) :: x, y, z
    real(wp) :: mag, mag2
    real(wp) :: riy, rjy, yim
    real(wp) :: magim, mag2im
    real(wp) :: rjx, rjz
    real(wp) :: rix, riz
  end type dis

end module cmn_tp_mod

program test_dis
  use cmn_tp_mod
  implicit none

  type(dis) :: test_var

  ! Test modification
  test_var%x = 1.0_wp
  test_var%y = 2.0_wp
  test_var%z = 3.0_wp

  ! Display the values to ensure everything is working
  print *, "x = ", test_var%x
  print *, "y = ", test_var%y
  print *, "z = ", test_var%z

end program test_dis