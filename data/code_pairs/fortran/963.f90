! File: mod_setprecision.f90
module mod_setprecision
  implicit none
  integer, parameter :: sprec = kind(1.0)
  integer, parameter :: dprec = kind(1.0d0)
end module mod_setprecision

! File: test_mod_setprecision.f90
program test_mod_setprecision
  use mod_setprecision
  implicit none

  if (sprec == kind(1.0)) then
    print *, "Test for single precision (sprec) passed."
  else
    print *, "Test for single precision (sprec) failed."
  end if

  if (dprec == kind(1.0d0)) then
    print *, "Test for double precision (dprec) passed."
  else
    print *, "Test for double precision (dprec) failed."
  end if
end program test_mod_setprecision