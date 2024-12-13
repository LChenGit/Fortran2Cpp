module Global_Variables
  implicit none
  integer :: NK_s, NK_e, NB, NL
  real(8) :: aLx, aLy, aLz, Hx, Hy, Hz
  real(8), allocatable :: zu_GS(:,:,:), Lx(:), Ly(:), Lz(:)
end module Global_Variables

program main
  use Global_Variables
  implicit none

  ! Initialize test global variables
  NK_s = 1
  NK_e = 2
  NB = 2
  NL = 3
  aLx = 1.0d0
  aLy = 2.0d0
  aLz = 3.0d0
  Hx = 0.1d0
  Hy = 0.2d0
  Hz = 0.3d0

  allocate(Lx(NL), Ly(NL), Lz(NL))
  allocate(zu_GS(NL, NB, NK_e))
  Lx = [1.0d0, 2.0d0, 3.0d0]
  Ly = [4.0d0, 5.0d0, 6.0d0]
  Lz = [7.0d0, 8.0d0, 9.0d0]

  call init_wf

  ! Print results for verification
  call print_results
  
  deallocate(Lx, Ly, Lz, zu_GS)
end program main

subroutine init_wf
  use Global_Variables
  implicit none
  integer :: iseed, ib, ik, i
  real(8) :: r2, x1, y1, z1, rnd

  do ik = NK_s, NK_e
    iseed = 123 + ik
    do ib = 1, NB
      call quickrnd(iseed, rnd)
      x1 = aLx * rnd
      call quickrnd(iseed, rnd)
      y1 = aLy * rnd
      call quickrnd(iseed, rnd)
      z1 = aLz * rnd
      do i = 1, NL
        r2 = (Lx(i) * Hx - x1)**2 + (Ly(i) * Hy - y1)**2 + (Lz(i) * Hz - z1)**2
        zu_GS(i, ib, ik) = exp(-0.5d0 * r2)
      end do
    end do
  end do
end subroutine init_wf

subroutine quickrnd(iseed, rnd)
  integer, parameter :: im = 6075, ia = 106, ic = 1283
  integer :: iseed
  real(8) :: rnd

  iseed = mod(iseed * ia + ic, im)
  rnd = dfloat(iseed) / dfloat(im)
end subroutine quickrnd

subroutine print_results
  use Global_Variables
  integer :: ik, ib, i
  do ik = NK_s, NK_e
    do ib = 1, NB
      do i = 1, NL
        print *, 'zu_GS(', i, ',', ib, ',', ik, ') = ', zu_GS(i, ib, ik)
      end do
    end do
  end do
end subroutine print_results