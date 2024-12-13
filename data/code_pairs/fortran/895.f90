module my_module
  implicit none
contains
  subroutine sub_rk(r)
    implicit none
    real(kind=8), dimension(:), intent(inout) :: r
    if (r(1) /= -1.0_8) stop "Assertion failed in sub_rk"
    if (r(2) /= -3.0_8) stop "Assertion failed in sub_rk"
    r(1) = 3.0_8
    r(2) = 2.0_8
  end subroutine sub_rk

  subroutine sub_ck(r)
    implicit none
    complex(kind=8), dimension(:), intent(inout) :: r
    if (r(1) /= cmplx(-1.0_8, 0.0_8, kind=8)) stop "Assertion failed in sub_ck"
    if (r(2) /= cmplx(-3.0_8, 0.0_8, kind=8)) stop "Assertion failed in sub_ck"
    r(1) = cmplx(3.0_8, 0.0_8, kind=8)
    r(2) = cmplx(2.0_8, 0.0_8, kind=8)
  end subroutine sub_ck
end module my_module

program main
  use my_module
  implicit none
  real(kind=8), dimension(3) :: rk
  complex(kind=8), dimension(3) :: ck

  rk = (/ -1.0_8, 1.0_8, -3.0_8 /)
  call sub_rk(rk(1:3:2))

  ck = (/ (-1.0_8, 0.0_8), (1.0_8, 0.0_8), (-3.0_8, 0.0_8) /)
  call sub_ck(ck(1:3:2))
end program main