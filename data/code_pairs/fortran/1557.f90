module bratu2d_mod
  implicit none
contains
  subroutine bratu2d(m, n, alpha, x, f)
    integer, intent(in) :: m, n
    real(kind=8), intent(in) :: alpha
    real(kind=8), dimension(m,n), intent(in) :: x
    real(kind=8), dimension(m,n), intent(inout) :: f
    integer :: i, j
    real(kind=8) :: hx, hy, u, uN, uS, uE, uW

    hx = 1.0d0 / (m - 1)
    hy = 1.0d0 / (n - 1)
    f = x

    do i = 2, m - 1
      do j = 2, n - 1
        u = x(i,j)
        uN = x(i-1,j)
        uS = x(i+1,j)
        uE = x(i,j+1)
        uW = x(i,j-1)

        f(i,j) = (2.0d0*u - uE - uW) * (hy/hx) + &
                 (2.0d0*u - uN - uS) * (hx/hy) - &
                 alpha * exp(u) * (hx * hy)
      end do
    end do
  end subroutine bratu2d
end module bratu2d_mod