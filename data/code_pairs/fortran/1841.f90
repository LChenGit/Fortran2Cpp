module m_tenstr_rrsw_kg23
  implicit none
  save

  integer, parameter :: im = 8 ! Assuming kind=8 for simplicity
  integer, parameter :: rb = 8
  integer, parameter :: ng23 = 10 ! Example value, adjust as necessary
  integer, parameter :: no23 = 16

  real(kind=rb) :: kao(5, 13, no23)
  real(kind=rb) :: selfrefo(10, no23), forrefo(3, no23)
  real(kind=rb) :: sfluxrefo(no23)
  real(kind=rb) :: raylo(no23)

  real(kind=rb) :: ka(5, 13, ng23), absa(65, ng23)
  real(kind=rb) :: selfref(10, ng23), forref(3, ng23)
  real(kind=rb) :: sfluxref(ng23), rayl(ng23)

  equivalence (ka(1, 1, 1), absa(1, 1))

end module m_tenstr_rrsw_kg23