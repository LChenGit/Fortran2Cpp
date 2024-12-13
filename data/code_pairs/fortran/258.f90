! main.f90
program main
    implicit none
    call great_rsd_add(2, 3)
end program main

subroutine great_rsd_add(kk1, ii1)
    implicit none
    integer, intent(in) :: kk1, ii1
    print *, 'Result of addition: ', kk1 + ii1
end subroutine great_rsd_add