program main
  implicit none
  integer :: a(2), b(2)
  integer :: x, y

  a = 1
  b = 0
  x = 1
  y = 0

  call mvbits(a, 0, 1, b, 1)
  call mvbits(x, 0, 1, y, 1)

  if (any(b /= y)) STOP 1
end program main