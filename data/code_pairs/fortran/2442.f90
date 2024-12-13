module my_functions
  implicit none
contains
  integer function f1(x, y)
    integer, intent(in) :: x, y
    f1 = x + y
  end function f1

  complex function f2(x)
    complex, intent(in) :: x
    f2 = x  ! Directly return input for simplicity
  end function f2

  real function f2b(x, y)
    real, intent(in) :: x, y
    f2b = x + y
  end function f2b
end module my_functions

program test
  use my_functions
  implicit none

  ! Variables for testing
  integer :: test_int_x = 1, test_int_y = 2
  real :: test_real_x = 1.1, test_real_y = 2.2
  complex :: test_complex_x = (1.1, 2.2)

  ! Test calls
  print *, "Testing f1:", f1(test_int_x, test_int_y)
  print *, "Testing f2:", f2(test_complex_x)
  print *, "Testing f2b:", f2b(test_real_x, test_real_y)
end program test