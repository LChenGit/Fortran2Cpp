module rrsw_kg22
  use, intrinsic :: iso_fortran_env, only: real64
  implicit none
  save

  integer, parameter :: no22 = 16
  integer, parameter :: ng22 = 16

  real(real64) :: kao(9,5,13,no22)
  real(real64) :: kbo(5,13:59,no22)
  real(real64) :: selfrefo(10,no22), forrefo(3,no22)
  real(real64) :: sfluxrefo(no22,9)

  real(real64) :: rayl

  real(real64) :: ka(9,5,13,ng22), absa(585,ng22)
  real(real64) :: kb(5,13:59,ng22), absb(235,ng22)
  real(real64) :: selfref(10,ng22), forref(3,ng22)
  real(real64) :: sfluxref(ng22,9)

  equivalence (ka, absa), (kb, absb)

contains

  subroutine test_equivalence
    print *, 'Testing equivalence within rrsw_kg22 module'
    ka(1,1,1,1) = 123.456
    print *, 'If equivalence works, this should print 123.456:', absa(1,1)
  end subroutine test_equivalence

end module rrsw_kg22

program main
  use rrsw_kg22
  implicit none

  call test_equivalence

end program main