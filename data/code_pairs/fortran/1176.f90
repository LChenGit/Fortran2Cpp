subroutine wrsoln(t,y)
  integer :: nnod, ntri
  common /mfe010/ nnod, ntri

  integer :: stats(8)
  double precision :: hlast
  real :: cpusec
  common /mfe070/ hlast, cpusec, stats

  double precision :: t, y(3,*)
  integer :: j

  open(unit=7, file='output.txt', status='replace', action='write')

  write(7,*) t
  do j=1,nnod
    write(7,*) y(2,j),y(3,j),y(1,j)
  end do
  write(7,*) hlast, cpusec, stats

  close(7)

end subroutine wrsoln