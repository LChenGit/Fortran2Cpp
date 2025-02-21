program test_program
    implicit none

    real :: test_temp = 5.0
    real, dimension(3) :: test_f = (/0.2, 0.4, 0.6/)
    real :: test_ent
    real, dimension(3) :: close_arr = (/1.0, 1.01, 1.02/)
    real, dimension(3) :: not_close_arr = (/1.0, 2.0, 3.0/)

contains

    subroutine entropy(f, temp, n, ent)
        implicit none
        real, intent(in) :: f(n)
        real, intent(in) :: temp
        integer, intent(in) :: n
        real, intent(out) :: ent
        integer :: i

        ent = 0.0
        do i = 1, n
            if (f(i) > 0) then
                ent = ent - f(i) * log(f(i))
            end if
        end do
        ent = ent / temp
    end subroutine entropy

    function has_close_elements(arr, n, tol)
        implicit none
        real, intent(in) :: arr(n)
        integer, intent(in) :: n
        real, intent(in) :: tol
        logical :: has_close_elements
        integer :: i

        has_close_elements = .true.
        do i = 1, n - 1
            if (abs(arr(i) - arr(i + 1)) > tol) then
                has_close_elements = .false.
                return
            end if
        end do
    end function has_close_elements

    subroutine test_entropy()
        real :: f(4) = (/0.2, 0.4, 0.6, 0.8/)
        real :: temp = 5.0
        integer :: n = 4
        real :: ent

        call entropy(f, temp, n, ent)
        print *, "Entropy: ", ent
    end subroutine test_entropy

    subroutine test_has_close_elements()
        if (.not. has_close_elements(close_arr, size(close_arr), 0.1)) then
            print *, "Test failed: close_arr does not have close elements"
        else
            print *, "Test passed: close_arr has close elements"
        end if

        if (has_close_elements(not_close_arr, size(not_close_arr), 0.1)) then
            print *, "Test failed: not_close_arr has close elements"
        else
            print *, "Test passed: not_close_arr does not have close elements"
        end if
    end subroutine test_has_close_elements

end program test_program