! phasefield_fort_bc2.f90
subroutine phasefield_fort_bc2(meqn, mbc, mx, my, xlower, ylower, dx, dy, q, t, dt, intersects_bc)
  implicit none
  integer, intent(in) :: meqn, mbc, mx, my
  double precision, intent(in) :: xlower, ylower, dx, dy, t, dt
  double precision, intent(inout) :: q(-mbc:mx+mbc, -mbc:my+mbc, meqn)
  integer, intent(in) :: intersects_bc(0:3)
  integer :: m, i, j, ibc, jbc

  do m=1,meqn
    if (intersects_bc(0) /= 0) then
        do ibc=1,mbc
            do j = -mbc,my+mbc
                q(-ibc,j,m) = q(0,j,m)
            end do
        end do
    endif

    if (intersects_bc(1) /= 0) then
        do ibc=1,mbc
           do j = -mbc,my+mbc
              q(mx+ibc,j,m) = q(mx,j,m)
           end do
       end do
    endif

    if (intersects_bc(2) /= 0) then
        do jbc=1,mbc
           do i = -mbc,mx+mbc
              q(i,-jbc,m) = q(i,0,m)
           end do 
        end do
    endif

    if (intersects_bc(3) /= 0) then
        do jbc=1,mbc
           do i = -mbc,mx+mbc
              q(i,my+jbc,m) = q(i,my,m)
           end do
       end do
   endif
  end do
end subroutine phasefield_fort_bc2

program test_phasefield_fort_bc2
  implicit none
  integer, parameter :: meqn=2, mbc=2, mx=5, my=5
  double precision :: q(-mbc:mx+mbc, -mbc:my+mbc, meqn)
  integer :: intersects_bc(0:3)
  double precision, parameter :: xlower=0.0, ylower=0.0, dx=1.0, dy=1.0, t=0.0, dt=1.0
  integer :: i, j, m

  q = 0.0
  q(-mbc:mx+mbc, -mbc:my+mbc, :) = 1.0  ! Set interior values to 1
  intersects_bc = (/1, 1, 1, 1/)

  call phasefield_fort_bc2(meqn, mbc, mx, my, xlower, ylower, dx, dy, q, t, dt, intersects_bc)

  do m = 1, meqn
    print *, 'Equation:', m
    do j = -mbc, my+mbc
      print '(10F5.1)', (q(i, j, m), i = -mbc, mx+mbc)
    end do
    print *
  end do
end program test_phasefield_fort_bc2