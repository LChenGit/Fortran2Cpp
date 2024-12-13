! main_program.f90
program main_program
  implicit none
  integer :: i
  
  i = 1
  if (1.lt.2) i=3
  print *, i

end program main_program