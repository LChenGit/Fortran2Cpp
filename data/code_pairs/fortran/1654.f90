program a
  implicit none
  integer, parameter :: i(4) = (/ 1, 1, 1, 1 /)
  integer :: z(4) = (/ 1, 1, -1, -1 /)
  where (z < 0) z = 1
  if (any(z /= i)) stop 1
end program a