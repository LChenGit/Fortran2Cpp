subroutine per_credat(x, y, nval, f, c, p, nf, epfl, ep, epoch, freq)
  implicit none
  
  ! Arguments
  integer, intent(in) :: nval, nf
  real, dimension(nval), intent(out) :: x, y
  double precision, dimension(:), intent(in) :: f, c, p, ep
  double precision, intent(in) :: epoch, freq
  logical, intent(in) :: epfl
  
  ! Local variables
  double precision :: delt, t
  integer :: i, j
  
  delt = (ep(2)-ep(1))/dble(nval-1)
  
  do i=1,nval
     if (epfl) then
        x(i) = ep(1) + dble(i-1)*delt
        t = (dble(x(i))-epoch)*6.283185d0
     else
        x(i) = real(i-1)/real(nval-1)
        t = (dble(x(i))/freq + ep(1) - epoch)*6.283185d0
     end if
     
     y(i) = c(1)
     
     do j = 1,nf
        y(i) = y(i) + c(j+1)*sin(t*f(j)+p(j))
     end do
  end do
  
end subroutine per_credat