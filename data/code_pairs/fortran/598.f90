module my_functions
  implicit none
contains
  real function f()
    f = 1.0
  end function f
end module my_functions

program main
  use my_functions
  implicit none
  integer :: a
  integer :: I
  logical, dimension(2) :: B
  real :: result

  ! Test 1: Test function f()
  result = f()
  if (result == 1.0) then
    print *, "Test 1 Passed"
  else
    print *, "Test 1 Failed"
  end if
  
  ! Setup for Test 2
  B = [ .true., .false. ]
  if (any(B)) then
    a = 12
  else
    a = 0
  end if
  if (a == 12) then
    print *, "Test 2 Passed"
  else
    print *, "Test 2 Failed"
  end if
  
  ! Setup for Test 3
  I = 1
  if (I /= 0) then
    a = 12
  else
    a = 0
  end if
  if (a == 12) then
    print *, "Test 3 Passed"
  else
    print *, "Test 3 Failed"
  end if
end program main