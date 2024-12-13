! great.f90
subroutine great_dd1_x1(dd1, x1)
    implicit none
    integer, intent(in) :: dd1, x1
    print *, "Great subroutine called with dd1, x1: ", dd1, x1
end subroutine great_dd1_x1

! Assuming we only demonstrate the one specific subroutine for simplicity
program test_great
    call great_dd1_x1(5, 10)
end program test_great