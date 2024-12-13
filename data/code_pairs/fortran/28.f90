program test_jgemmx
  implicit none
  integer(KIND=8), parameter :: m = 2, n = 2, k = 2
  integer(KIND=8), parameter :: alpha = 1, beta = 1
  integer(KIND=8) :: a(m*n), b(m*n), c(m*n)
  integer(KIND=8) :: inc1a = 1, inc2a = 2, inc1b = 1, inc2b = 2, inc1c = 1, inc2c = 2

  a = (/1, 2, 3, 4/)
  b = (/5, 6, 7, 8/)

  call JGEMMX(m, n, k, alpha, a, inc1a, inc2a, b, inc1b, inc2b, beta, c, inc1c, inc2c)

  print *, "Results for C:"
  print *, c

contains

  subroutine JGEMMX(m, n, k, alpha, a, inc1a, inc2a, b, inc1b, inc2b, beta, c, inc1c, inc2c)
    integer(KIND=8), intent(in) :: m, n, k
    integer(KIND=8), intent(in) :: alpha, beta
    integer(KIND=8), intent(in) :: a(*), b(*)
    integer(KIND=8), intent(out) :: c(*)
    integer(KIND=8), intent(in) :: inc1a, inc2a, inc1b, inc2b, inc1c, inc2c

    integer :: i
    do i = 1, m*n
        c(i) = alpha * a(i) + beta * b(i)
    end do
  end subroutine JGEMMX

end program test_jgemmx