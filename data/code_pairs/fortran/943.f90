subroutine qinit(maxmx,meqn,mbc,mx,xlower,dx,q,maux,aux)
  implicit double precision (a-h,o-z)
  integer :: maxmx, meqn, mbc, mx, maux
  double precision :: xlower, dx
  double precision, dimension(1-mbc:maxmx+mbc, meqn) :: q
  double precision, dimension(1-mbc:maxmx+mbc, *) :: aux
  double precision :: xcell, ql, qr
  integer :: i

  common /comic/ beta

  ql = 0.13d0
  qr = 0.1d0

  do i=1,mx
     xcell = xlower + (i-0.5d0)*dx
     if (xcell .lt. 0.d0) then
         q(i,1) = ql
       else
         q(i,1) = qr
     endif
  end do

  return
end subroutine qinit