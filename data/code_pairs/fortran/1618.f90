! mysub.f90
subroutine mysub
end subroutine mysub

program test_mysub
    implicit none

    call mysub

    print *, "Fortran subroutine called successfully."
end program test_mysub