! Define custom types in a module or specify directly
! For the sake of simplicity, let's define them directly here
module types
    implicit none
    integer, parameter :: TINTEGER = kind(0)
    real, parameter :: TREAL = kind(0.0)
end module types

module fpchep_module
    use types
    implicit none
contains
    subroutine fpchep(x, m, t, n, k, ier)
        implicit none
        integer(TINTEGER), intent(in) :: m, n, k
        real(TREAL), intent(in) :: x(m), t(n)
        integer(TINTEGER), intent(out) :: ier
        integer(TINTEGER) :: i, j, k1, k2, nk1, nk2

        k1 = k + 1
        k2 = k1 + 1
        nk1 = n - k1
        nk2 = nk1 + 1
        
        ier = 10 ! Initial error state
        
        if (nk1 < k1 .or. n > m + 2 * k) return
        
        do i = 1, k
            if (t(i) > t(i+1)) return
        end do

        ier = 0 ! No errors found
    end subroutine fpchep
end module fpchep_module

program test_fpchep
    use types
    use fpchep_module
    implicit none
    integer(TINTEGER) :: ier
    integer(TINTEGER), parameter :: m = 5, n = 7, k = 2
    real(TREAL) :: x(m) = [1.0, 2.0, 3.0, 4.0, 5.0]
    real(TREAL) :: t(n) = [0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0]

    call fpchep(x, m, t, n, k, ier)
    
    print *, "Fortran Test Case 1: IER =", ier
    if (ier == 0) then
        print *, "PASS"
    else
        print *, "FAIL"
    end if
end program test_fpchep