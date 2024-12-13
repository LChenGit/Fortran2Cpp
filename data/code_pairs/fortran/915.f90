subroutine sedivm(n, dx, incx, dy, incy)
  implicit none
  integer, intent(in) :: n, incx, incy
  real, intent(in) :: dx(*)
  real, intent(inout) :: dy(*)
  integer :: i, ix, iy

  if (n.le.0) return
  ix = 1
  iy = 1
  if (incx < 0) ix = (-n + 1) * incx + 1
  if (incy < 0) iy = (-n + 1) * incy + 1

  do i = 1, n
     dy(iy) = dy(iy) / dx(ix)
     ix = ix + incx
     iy = iy + incy
  end do
end subroutine sedivm