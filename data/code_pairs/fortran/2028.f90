subroutine knum(n, nu0, numax, z, eps, a, b, rho, rold, ierr)
  implicit none
  integer, intent(in) :: n, numax
  integer :: nu0
  complex, intent(in) :: z
  real, intent(in) :: eps
  real, dimension(numax), intent(in) :: a, b
  complex, dimension(:), intent(out) :: rho, rold
  integer, intent(out) :: ierr
  complex :: r
  integer :: k, j, j1, np1, nu

  ierr = 0
  np1 = n + 1
  if (nu0 > numax) then
    ierr = nu0
    return
  endif
  if (nu0 < np1) nu0 = np1
  nu = nu0 - 5
  do k = 1, np1
     rho(k) = (0.0, 0.0)
  end do

  do while (.true.)
     nu = nu + 5
     if (nu > numax) then
        ierr = numax
        return
     endif
     rold = rho
     do j = 1, nu
        j1 = nu - j + 1
        r = cmplx(b(j1), 0.0) / (z - cmplx(a(j1), 0.0) - r)
        if (j1 <= np1) then
           rho(j1) = r
        endif
     end do
     do k = 1, np1
        if (abs(rho(k) - rold(k)) > eps * abs(rho(k))) then
           exit
        endif
     end do
     exit
  end do

  if (n == 0) return
  do k = 2, np1
     rho(k) = rho(k) * rho(k-1)
  end do
end subroutine knum