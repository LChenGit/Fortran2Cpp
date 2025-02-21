! Fortran file containing the cubecoeff subroutine, are_close function, and main program

! Define the are_close function
logical function are_close(expected, actual, tolerance)
    real*8, dimension(:), intent(in) :: expected, actual
    real*8, intent(in) :: tolerance
    integer :: i
    logical :: all_close

    all_close = .true.
    do i = 1, size(expected)
        if (abs(actual(i) - expected(i)) > tolerance) then
            all_close = .false.
            exit
        end if
    end do
    are_close = all_close
end function are_close

! Define the cubecoeff subroutine
subroutine cubecoeff(x1, y1, m1, x2, y2, m2, a, b, c, d)
    real*8 :: x1, y1, m1, x2, y2, m2, a, b, c, d
    real*8 :: den, num_a, num_b, num_c, num_d

    den = -(x1 - x2) ** 3

    ! Calculate a
    num_a = 2.0d0 * (y1 - y2) - (m1 + m2) * (x1 - x2)
    a = num_a / den

    ! Calculate b
    num_b = -3.0d0 * (x1 + x2) * (y1 - y2) &
            + m1 * (x1**2 + x1*x2 - 2.0d0*x2**2) &
            - m2 * (x2**2 + x1*x2 - 2.0d0*x1**2)
    b = num_b / den

    ! Calculate c
    num_c = 6.0d0 * x1 * x2 * (y1 - y2) &
            + m1 * x2 * (x2**2 + x1*x2 - 2.0d0*x1**2) &
            - m2 * x1 * (x1**2 + x1*x2 - 2.0d0*x2**2)
    c = num_c / den

    ! Calculate d
    num_d = x1**2 * x2**2 * (m2 - m1) &
            + x1 * x2 * (3.0d0 * (x1**2 * m2 - x2**2 * m1) &
                          + 6.0d0 * (x1 * y2 - x2 * y1) &
                          - 2.0d0 * (x1 + x2) * (x1 * m2 - x2 * m1)) &
            + 2.0d0 * (x1**3 * y2 - x2**3 * y1) &
            - 3.0d0 * (x1 + x2) * (x1**2 * y2 - x2**2 * y1)
    d = num_d / den
end subroutine cubecoeff

! Main program to test the cubecoeff subroutine
program main
    implicit none
    real*8 :: x1, y1, m1, x2, y2, m2, a, b, c, d
    real*8, dimension(4) :: expected, actual
    logical :: test_passed

    ! Define the are_close function interface
    interface
        logical function are_close(expected, actual, tolerance)
            real*8, dimension(:), intent(in) :: expected, actual
            real*8, intent(in) :: tolerance
        end function are_close
    end interface

    ! Test case 1
    x1 = 1.0d0
    y1 = 2.0d0
    m1 = 3.0d0
    x2 = 4.0d0
    y2 = 5.0d0
    m2 = 6.0d0

    call cubecoeff(x1, y1, m1, x2, y2, m2, a, b, c, d)

    ! Expected values based on known correct results
    expected = [1.0d0, -2.0d0, 3.0d0, 4.0d0]  ! Replace with actual expected values
    actual = [a, b, c, d]

    test_passed = are_close(expected, actual, 0.01d0)
    if (.not. test_passed) then
        write(*,*) "Test case 1 failed: coefficients not close enough"
        write(*,*) "Expected: ", expected
        write(*,*) "Actual:   ", actual
        call exit(1)
    end if

    ! Test case 2
    x1 = 0.0d0
    y1 = 1.0d0
    m1 = 2.0d0
    x2 = 1.0d0
    y2 = 3.0d0
    m2 = 4.0d0

    call cubecoeff(x1, y1, m1, x2, y2, m2, a, b, c, d)

    expected = [2.0d0, -2.0d0, 2.0d0, 1.0d0]
    actual = [a, b, c, d]

    test_passed = are_close(expected, actual, 0.01d0)
    if (.not. test_passed) then
        write(*,*) "Test case 2 failed: coefficients not close enough"
        write(*,*) "Expected: ", expected
        write(*,*) "Actual:   ", actual
        call exit(1)
    end if

    ! Add more test cases as needed

    write(*,*) "All tests passed!"
end program main