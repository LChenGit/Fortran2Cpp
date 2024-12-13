! myModule.f90
module myModule
  implicit none
contains

  real function e1(x)
    real, intent(in) :: x
    e1 = x * 3.0
  end function e1

  subroutine e2(a, b)
    real, intent(inout) :: a
    real, intent(in) :: b
    a = a + b
  end subroutine e2

end module myModule

program proc_ptr_3
  use myModule
  implicit none

  interface
    real function fp(x)
      real, intent(in) :: x
    end function fp
  end interface

  interface
    subroutine sp(a, b)
      real, intent(inout) :: a
      real, intent(in) :: b
    end subroutine sp
  end interface

  real :: c = 1.2
  external :: e1
  pointer :: pf
  pf = loc(e1)

  if (abs(fp(2.5) - 7.5) > 0.01) stop 1

  c = 1.2
  call e2(c, 3.4)

  if (abs(c - 4.6) > 0.01) stop 2

end program proc_ptr_3