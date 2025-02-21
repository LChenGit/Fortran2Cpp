module main_module
    implicit none

contains
    logical function has_close_elements(a, b, n, tol)
        implicit none
        integer :: n
        real(kind=8) :: a(n), b(n), tol

        integer :: i
        has_close_elements = .true.
        do i = 1, n
            if (abs(a(i) - b(i)) > tol) then
                has_close_elements = .false.
                return
            end if
        end do
    end function has_close_elements
end module main_module

program test_has_close_elements
    use main_module
    implicit none
    real(kind=8) :: a(2), b(2)
    logical :: result
    integer, parameter :: ndim = 2
    real(kind=8) :: f(ndim)
    real(kind=8), parameter :: expected_f(ndim) = (/ -3.0d0, -4.0d0 /)
    real(kind=8), parameter :: tol = 1e-6_8

    a = (/ 1.000001d0, 2.000001d0 /)
    b = (/ 1.0d0, 2.0d0 /)

    result = has_close_elements(a, b, ndim, tol)
    if (result) then
        write(*,*) "Test passed: arrays have close elements"
    else
        write(*,*) "Test failed: arrays do not have close elements"
    end if

    f = (/ -3.0d0, -4.0d0 /)
    if (.not. has_close_elements(f, expected_f, ndim, tol)) then
        write(*,*) "Test failed: function values do not match expected values"
    else
        write(*,*) "Test passed: function values match expected values"
    end if

end program test_has_close_elements