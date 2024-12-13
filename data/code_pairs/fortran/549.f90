! fclaw2d_clawpatch5_fort_timeinterp.f90
subroutine fclaw2d_clawpatch5_fort_timeinterp(mx, my, mbc, meqn, psize, qcurr, qlast, qinterp, alpha, ierror)
  implicit none

  integer :: mx, my, mbc, meqn, psize, ierror
  double precision :: alpha
  double precision :: qcurr(meqn, 1-mbc:mx+mbc, 1-mbc:my+mbc)
  double precision :: qlast(meqn, 1-mbc:mx+mbc, 1-mbc:my+mbc)
  double precision :: qinterp(meqn, 1-mbc:mx+mbc, 1-mbc:my+mbc)

  integer :: i, j, m

  ierror = 0

  do m = 1, meqn
    do j = 1, my
      do i = 1, mx
        qinterp(m, i, j) = qlast(m, i, j) + alpha * (qcurr(m, i, j) - qlast(m, i, j))
      end do
    end do
  end do
end subroutine fclaw2d_clawpatch5_fort_timeinterp

! test_fortran.f90
program test_fortran
  implicit none
  integer, parameter :: mx=10, my=10, mbc=2, meqn=1, psize=100
  double precision, allocatable :: qcurr(:,:,:), qlast(:,:,:), qinterp(:,:,:)
  double precision :: alpha = 0.5
  integer :: ierror

  allocate(qcurr(meqn, 1-mbc:mx+mbc, 1-mbc:my+mbc))
  allocate(qlast(meqn, 1-mbc:mx+mbc, 1-mbc:my+mbc))
  allocate(qinterp(meqn, 1-mbc:mx+mbc, 1-mbc:my+mbc))

  ! Initialize qcurr and qlast with some test values
  qcurr = 1.0
  qlast = 0.5

  call fclaw2d_clawpatch5_fort_timeinterp(mx, my, mbc, meqn, psize, qcurr, qlast, qinterp, alpha, ierror)

  ! Write qinterp to standard output or check its values
  print *, qinterp

  deallocate(qcurr, qlast, qinterp)
end program test_fortran