module ieee_operations
    use ieee_arithmetic
    implicit none
contains
    function check_operations() result(res)
        integer :: res
        real :: x
        real(8) :: y

        res = 0

        x = ieee_value(x, ieee_signaling_nan)
        if (.not. ieee_is_nan(x)) then
            res = 1
            return
        endif
        x = ieee_value(x, ieee_quiet_nan)
        if (.not. ieee_is_nan(x)) then
            res = 2
            return
        endif

        x = ieee_value(x, ieee_positive_inf)
        if (ieee_is_finite(x)) then
            res = 3
            return
        endif
        x = ieee_value(x, ieee_negative_inf)
        if (ieee_is_finite(x)) then
            res = 4
            return
        endif

        y = ieee_value(y, ieee_signaling_nan)
        if (.not. ieee_is_nan(y)) then
            res = 5
            return
        endif
        y = ieee_value(y, ieee_quiet_nan)
        if (.not. ieee_is_nan(y)) then
            res = 6
            return
        endif

        y = ieee_value(y, ieee_positive_inf)
        if (ieee_is_finite(y)) then
            res = 7
            return
        endif
        y = ieee_value(y, ieee_negative_inf)
        if (ieee_is_finite(y)) then
            res = 8
            return
        endif
    end function check_operations
end module ieee_operations

program test_program
    use ieee_operations
    implicit none
    integer :: test_result

    test_result = check_operations()
    if (test_result /= 0) then
        print *, "Test failed with code:", test_result
    else
        print *, "All tests passed."
    endif
end program test_program