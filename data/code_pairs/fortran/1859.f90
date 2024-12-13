module rrlw_kg04
    implicit none
    save

    integer(kind=4), parameter :: no4 = 16, ng4 = 14

    real(kind=8) :: fracrefao(no4,9), fracrefbo(no4,5)
    real(kind=8) :: kao(9,5,13,no4)
    real(kind=8) :: kbo(5,5,47,no4)  ! Adjusted for 13:59 range
    real(kind=8) :: selfrefo(10,no4), forrefo(4,no4)

    real(kind=8) :: fracrefa(ng4,9), fracrefb(ng4,5)
    real(kind=8) :: ka(9,5,13,ng4)
    real(kind=8) :: kb(5,5,47,ng4)  ! Adjusted for 13:59 range
    real(kind=8) :: absa(585,ng4)
    real(kind=8) :: absb(1175,ng4)
    real(kind=8) :: selfref(10,ng4), forref(4,ng4)

    equivalence (ka(1,1,1,1), absa(1,1)), (kb(1,1,13,1), absb(1,1))
end module rrlw_kg04