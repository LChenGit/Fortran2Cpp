module factorial_module
  implicit none
contains
  subroutine calculate_factorial(n, result)
    integer, intent(in) :: n
    integer, intent(out) :: result
    integer :: i
    result = 1
    do i = 1, n
       result = result * i
    end do
  end subroutine calculate_factorial
end module factorial_module

program test_factorial
  use factorial_module
  implicit none
  integer :: result, i

  ! Test the calculate_factorial subroutine with various inputs
  do i = 0, 5
     call calculate_factorial(i, result)
     print *, "Factorial of", i, "is", result
  end do
end program test_factorial