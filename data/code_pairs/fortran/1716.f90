! test.f90
program test
  implicit none
  integer :: a
  a = 0
  if (.true.) then
     ! Intentionally left blank.
  else
     a = 1
  end if
  print *, 'Value of a:', a
end program test