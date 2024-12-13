module array_functions
  implicit none
contains
  integer function f(x)
    integer, dimension(:), intent(in) :: x
    f = sum(x)
  end function f
end module array_functions

program test_fortran_code
  use array_functions
  integer :: a(5), b, l, u

  ! Initialize array and boundary values
  a = (/ 1, 2, 3, 4, 5 /)
  l = 4
  u = 2

  ! Perform operations and print results
  b = f(a(l:u:-1) - 2)
  print *, "Result in Fortran program:", b
end program test_fortran_code