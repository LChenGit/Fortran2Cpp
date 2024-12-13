module rrsw_kg25_mod
  implicit none
  save

  ! Assuming the kinds are predefined for the purpose of this example
  integer, parameter :: im = selected_int_kind(15)
  integer, parameter :: rb = selected_real_kind(6, 37)

  integer, parameter :: no25 = 16
  integer, parameter :: ng25 = 20 ! Example value; adjust as needed

  real(kind=rb) :: kao(5,13,no25)
  real(kind=rb) :: sfluxrefo(no25)
  real(kind=rb) :: abso3ao(no25), abso3bo(no25)
  real(kind=rb) :: raylo(no25)

  real(kind=rb) :: ka(5,13,ng25), absa(65,ng25)
  real(kind=rb) :: sfluxref(ng25)
  real(kind=rb) :: abso3a(ng25), abso3b(ng25)
  real(kind=rb) :: rayl(ng25)

end module rrsw_kg25_mod