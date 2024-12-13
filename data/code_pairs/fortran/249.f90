module iarnan_module
  implicit none
contains
  subroutine IARNAN(NUM, INFO)
    ! Using IEEE arithmetic module for NaN checks
    use, intrinsic :: ieee_arithmetic
    implicit none
    real, intent(in) :: NUM
    integer, intent(inout) :: INFO

    INFO = 0

    if (ieee_is_nan(NUM)) then
      INFO = 1
    end if
  end subroutine IARNAN
end module iarnan_module

program test_iarnan
  use iarnan_module
  use, intrinsic :: ieee_arithmetic
  implicit none

  real :: num
  integer :: info

  ! Test with a normal number
  num = 1.0
  call IARNAN(num, info)
  print *, "Test with 1.0, Expected INFO=0, Got INFO=", info

  ! Test with NaN
  num = ieee_value(num, ieee_quiet_nan)
  call IARNAN(num, info)
  print *, "Test with NaN, Expected INFO=1, Got INFO=", info
end program test_iarnan