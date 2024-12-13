module factorial_module
  implicit none
contains
  integer function factorial(n)
    implicit none
    integer, intent(in) :: n
    integer :: i

    factorial = 1
    do i = n, 2, -1
      factorial = factorial * i
    end do
  end function factorial
end module factorial_module