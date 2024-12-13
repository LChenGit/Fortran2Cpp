subroutine decodems(cdat, npts, cw, i1, nchar, s2, msg)
  implicit none
  complex, intent(in) :: cdat(*)
  complex, intent(in) :: cw(56,0:63)
  real, intent(out) :: s2(0:63,*)
  character(len=*), intent(out) :: msg
  integer, intent(in) :: npts, i1, nchar
  complex :: z
  character(len=64) :: cc
  integer :: i, j, k, kk, ia, kpk
  real :: smax, ss

  data cc/'0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ./?-                 _     @'/

  msg = ''
  do j = 1, nchar
     ia = i1 + (j-1)*56
     smax = 0.0
     do k = 0, 40
        kk = k
        if (k == 40) kk = 57
        z = (0.0, 0.0)
        do i = 1, 56
           z = z + cdat(ia+i) * conjg(cw(i,kk))
        end do
        ss = abs(z)
        s2(k,j) = ss
        if (ss > smax) then
           smax = ss
           kpk = kk
        end if
     end do
     msg(j:j) = cc(kpk+1:kpk+1)
     if (kpk == 57) msg(j:j) = ' '
  end do
end subroutine decodems