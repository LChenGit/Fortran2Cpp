module rrlw_kg03
    implicit none
    save

    ! Assuming kind parameter definitions for demonstration
    integer, parameter :: im = selected_int_kind(8)
    integer, parameter :: rb = selected_real_kind(p=6, r=37)

    ! Constants
    integer(kind=im), parameter :: no3 = 16
    real(kind=rb) :: fracrefao(no3,9), fracrefbo(no3,5)
    real(kind=rb) :: kao(9,5,13,no3)
    real(kind=rb) :: kbo(5,5,47,no3) ! Adjusted for 0-based indexing in tests
    real(kind=rb) :: kao_mn2o(9,19,no3), kbo_mn2o(5,19,no3)
    real(kind=rb) :: selfrefo(10,no3)
    real(kind=rb) :: forrefo(4,no3)

    integer(kind=im), parameter :: ng3 = 16
    real(kind=rb) :: fracrefa(ng3,9), fracrefb(ng3,5)
    real(kind=rb) :: ka(9,5,13,ng3)
    real(kind=rb) :: kb(5,5,47,ng3) ! Adjusted for 0-based indexing in tests
    real(kind=rb) :: ka_mn2o(9,19,ng3), kb_mn2o(5,19,ng3)
    real(kind=rb) :: selfref(10,ng3)
    real(kind=rb) :: forref(4,ng3)

end module rrlw_kg03