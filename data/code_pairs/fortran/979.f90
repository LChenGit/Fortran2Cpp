program chop
  implicit none
  integer :: ix, iy
  real :: x, y

  x = 1.0
  y = x
  ix = transfer(x, ix)
  iy = transfer(y, iy)

  print '(2z20.8)', ix, iy

  if (ix /= iy) then
    call abort
  endif
end program chop