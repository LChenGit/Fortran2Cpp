! This Fortran program demonstrates manipulation of strings and pointers.
program test
  implicit none
  character(len=7), target :: textt
  character(len=7), pointer :: textp
  character(len=5), pointer :: textp2

  ! Point textp to textt
  textp => textt
  ! Point textp2 to the first 5 characters of textt
  textp2 => textt(1:5)

  ! Initial length checks
  if (len(textp) /= 7) stop 1
  if (len(textp2) /= 5) stop 2

  ! Modify the strings through pointers
  textp = 'aaaaaaa'
  textp2 = 'bbbbb'

  ! Final value checks
  if (textp /= 'bbbbbaa') stop 3
  if (textp2 /= 'bbbbb') stop 4

  print *, 'All tests passed successfully!'
end program test