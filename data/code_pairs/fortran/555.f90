module m_tenstr_rrlw_kg14
  implicit none
  save

  integer, parameter :: no14 = 16
  integer, parameter :: ng14 = 2

  ! Assuming the kinds are predefined elsewhere or using default
  real, dimension(no14) :: fracrefao
  real, dimension(no14) :: fracrefbo

  real :: kao(5,13,no14)
  real :: kbo(5,13:59,no14)
  real :: selfrefo(10,no14)
  real :: forrefo(4,no14)

  real, dimension(ng14) :: fracrefa
  real, dimension(ng14) :: fracrefb

  real :: ka(5,13,ng14), absa(65,ng14)
  real :: kb(5,13:59,ng14), absb(235,ng14)
  real :: selfref(10,ng14)
  real :: forref(4,ng14)

  equivalence (ka(1,1,1), absa(1,1)), (kb(1,13,1), absb(1,1))

end module m_tenstr_rrlw_kg14