program array_char
  implicit none
  integer :: i
  integer, allocatable :: j(:)
  character(len=5) :: x, y
  character(len=5), allocatable :: z(:)
  allocate(j(5))
  allocate(z(2))
  
  x = "ab"
  y = "cd"
  z = [y(1:len(trim(y))) // x(1:len(trim(x))), x(1:len(trim(x))) // y(1:len(trim(y)))]
  
  j = [(ichar(z(1)(i:i)), i=1,5)]
  if (any(j /= [99,100,32,32,32])) stop 1
  
  j = [(ichar(z(2)(i:i)), i=1,5)]
  if (any(j /= [97,98,32,32,32])) stop 2
  
  x = "a "
  z = [y(1:len(trim(y))) // x(1:len(trim(x))), x(1:len(trim(x))) // y(1:len(trim(y)))]
  
  print *, "Fortran code executed successfully."
end program array_char