module Utilities
  implicit none
contains
  subroutine swapInteger(a, b)
    integer, intent(inout) :: a, b
    integer :: tmp
    tmp = a
    a = b
    b = tmp
  end subroutine swapInteger
  
  subroutine swapReal(a, b)
    real, intent(inout) :: a, b
    real :: tmp
    tmp = a
    a = b
    b = tmp
  end subroutine swapReal
end module Utilities