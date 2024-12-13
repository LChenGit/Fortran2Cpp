subroutine utemp_ccxlib(temp, msecpt, kstep, kinc, time, node, coords, vold, mi)
  implicit none
  integer :: msecpt, kstep, kinc, node, mi(*)
  real*8 :: temp(msecpt), time(2), coords(3), vold(0:mi(2),*)
  temp(1) = 293.d0
end subroutine utemp_ccxlib