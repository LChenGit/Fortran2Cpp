! dswap.f90
subroutine dswap(N, dx, strideX, dy, strideY)
  implicit none
  integer :: strideX, strideY, N
  double precision :: dx(*), dy(*)
  double precision :: tmp
  integer :: ix, iy, i

  if (N <= 0) then
    return
  end if

  ix = 1
  iy = 1
  do i = 1, N
    tmp = dx(ix)
    dx(ix) = dy(iy)
    dy(iy) = tmp
    ix = ix + strideX
    iy = iy + strideY
  end do
end subroutine dswap

program test_dswap
  implicit none
  double precision, allocatable :: dx(:), dy(:)
  integer :: N, strideX, strideY

  ! Test case with N=3, stride=1 (optimized path)
  N = 3
  allocate(dx(N), dy(N))
  dx = [1.0d0, 2.0d0, 3.0d0]
  dy = [4.0d0, 5.0d0, 6.0d0]
  strideX = 1
  strideY = 1

  call dswap(N, dx, strideX, dy, strideY)

  print *, 'Fortran code: Test passed if dx and dy are swapped correctly.'
  print *, 'dx = ', dx
  print *, 'dy = ', dy

  ! Free allocated memory
  deallocate(dx, dy)
end program test_dswap