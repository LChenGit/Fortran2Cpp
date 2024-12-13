module factorial_mod
  implicit none
contains
  integer function factorial(n)
    integer, intent(in) :: n
    integer :: i
    factorial = 1
    do i = 1, n
       factorial = factorial * i
    end do
  end function factorial
end module factorial_mod

program test_factorial
  use factorial_mod
  implicit none
  integer :: errors
  errors = 0

  ! Test 1: Factorial of 0
  if (factorial(0) /= 1) then
     print *, 'Test 1 failed: Factorial(0) should be 1'
     errors = errors + 1
  endif

  ! Test 2: Factorial of 1
  if (factorial(1) /= 1) then
     print *, 'Test 2 failed: Factorial(1) should be 1'
     errors = errors + 1
  endif

  ! Test 3: Factorial of 5
  if (factorial(5) /= 120) then
     print *, 'Test 3 failed: Factorial(5) should be 120'
     errors = errors + 1
  endif

  ! Summary
  if (errors == 0) then
     print *, 'All tests passed!'
  else
     print *, errors, ' tests failed.'
  endif
end program test_factorial