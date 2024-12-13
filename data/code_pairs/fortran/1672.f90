module calculations
    implicit none
contains
    subroutine initialize_globals()
        ! Dummy subroutine for initialization, if needed
    end subroutine initialize_globals

    real function perform_some_calculation()
        perform_some_calculation = 42.0
    end function perform_some_calculation
end module calculations

program test_calculation
    use calculations
    implicit none
    real :: result
    real, parameter :: expected_result = 42.0

    call initialize_globals()
    result = perform_some_calculation()

    if (abs(result - expected_result) < 1.0e-6) then
        print *, "Test passed."
    else
        print *, "Test failed: Result =", result
    endif
end program test_calculation