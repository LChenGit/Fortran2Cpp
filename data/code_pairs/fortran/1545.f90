subroutine dgemv(trans, m, n, alpha, A, lda, x, incx, beta, y, incy)
  implicit none
  character*1, intent(in) :: trans
  integer, intent(in) :: m, n, lda, incx, incy
  double precision, intent(in) :: alpha, beta
  double precision, intent(in) :: A(lda, *)
  double precision, intent(in) :: x(*)
  double precision, intent(inout) :: y(*)
  integer :: i, j

  do i = 1, m
    do j = 1, n
      y(i) = y(i) + A(i, j) * x(j)
    end do
  end do
end subroutine dgemv