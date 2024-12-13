! caxpy.f90
subroutine caxpy(n, ca, cx, incx, cy, incy)
  complex, intent(in) :: cx(*), ca
  complex, intent(inout) :: cy(*)
  integer, intent(in) :: n, incx, incy
  integer :: i, ix, iy

  if (n <= 0) return
  if (abs(real(ca)) + abs(aimag(ca)) == 0.0) return
  if (incx == 1 .and. incy == 1) then
    do i = 1, n
      cy(i) = cy(i) + ca * cx(i)
    end do
  else
    ix = 1
    iy = 1
    if (incx < 0) ix = (-n + 1) * incx + 1
    if (incy < 0) iy = (-n + 1) * incy + 1
    do i = 1, n
      cy(iy) = cy(iy) + ca * cx(ix)
      ix = ix + incx
      iy = iy + incy
    end do
  endif
end subroutine caxpy