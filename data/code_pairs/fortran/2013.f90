program test
  implicit none

  integer(kind=1) :: i1
  integer(kind=2) :: i2
  integer(kind=4) :: i4
  integer(kind=8) :: i8
  real(kind=8) :: r
  character(len=2) :: s1, s2

  i1 = 1 ; i2 = 1 ; i4 = 1 ; i8 = 1
  r = 1.0
  s1 = '42'
  
  s2 = repeat(s1,i1)
  if (s2 /= s1) stop "1"
  s2 = repeat(s1,i2)
  if (s2 /= s1) stop "2"
  s2 = repeat(s1,i4)
  if (s2 /= s1) stop "3"
  s2 = repeat(s1,i8)
  if (s2 /= s1) stop "4"

  print *, "All tests passed successfully."
end program test