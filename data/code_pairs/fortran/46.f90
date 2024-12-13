! Module definition
module assignment_module
    implicit none
    real :: XYTRAN_TRCOEFFS = 0.0
    real :: XYFIT_TRCOEFFS = 5.0
contains
    ! The subroutine to perform the assignment
    subroutine perform_assignment()
        XYTRAN_TRCOEFFS = XYFIT_TRCOEFFS
    end subroutine perform_assignment
end module assignment_module

! Test program
program test_program
    use assignment_module
    implicit none
    call perform_assignment()
    if (XYTRAN_TRCOEFFS == XYFIT_TRCOEFFS) then
        print *, "Test passed."
    else
        print *, "Test failed."
    end if
end program test_program