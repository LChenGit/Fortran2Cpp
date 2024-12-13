subroutine foo(x, nnd)
  double precision, dimension(nnd) :: x
  integer :: i
  
  do i=1, nnd
    x(i) = 1.d0 + (1.d0*i)/nnd
  end do
end subroutine foo