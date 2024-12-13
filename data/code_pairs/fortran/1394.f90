module cdat_mod
  implicit none
  real*8 :: al
  real*8 :: beta
contains
  subroutine init_pars()
    implicit none
    al = 16d0
    beta = 128d0
  end subroutine init_pars
end module cdat_mod

program test_init_pars
  use cdat_mod
  implicit none

  call init_pars()

  if (al == 16d0 .and. beta == 128d0) then
    print *, "Test passed."
  else
    print *, "Test failed."
  end if
end program test_init_pars