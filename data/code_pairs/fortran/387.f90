module modglobal
  implicit none
  integer, parameter :: kind_im = 4 ! Assuming default kind
  integer, parameter :: kind_rb = 8 ! Assuming double precision
end module modglobal

module parrrsw
  implicit none
  integer, parameter :: ng20 = 20 ! Example value, adjust as necessary
end module parrrsw

module rrsw_kg20
  use modglobal, only: im => kind_im, rb => kind_rb
  use parrrsw, only: ng20

  implicit none
  save

  integer(kind=im), parameter :: no20 = 16

  real(kind=rb) :: kao(5,13,no20)
  real(kind=rb) :: kbo(5,13:59,no20)
  real(kind=rb) :: selfrefo(10,no20), forrefo(4,no20)
  real(kind=rb) :: sfluxrefo(no20)
  real(kind=rb) :: absch4o(no20)

  real(kind=rb) :: rayl

  real(kind=rb) :: ka(5,13,ng20), absa(65,ng20)
  real(kind=rb) :: kb(5,13:59,ng20), absb(235,ng20)
  real(kind=rb) :: selfref(10,ng20), forref(4,ng20)
  real(kind=rb) :: sfluxref(ng20)
  real(kind=rb) :: absch4(ng20)
end module rrsw_kg20