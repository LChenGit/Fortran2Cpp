module fi_a3_module
contains
    subroutine fi_a3(r, p)
        implicit none
        real(kind=8), intent(in) :: r(3)
        real(kind=8), intent(out) :: p(3)
        p(1) = r(1) + r(2) + r(3)
        p(2) = r(1)**2 + r(2)**2 + r(3)**2
        p(3) = r(1)**3 + r(2)**3 + r(3)**3
    end subroutine fi_a3
end module fi_a3_module

program test_fi_a3
    use fi_a3_module
    implicit none
    real(kind=8) :: r(3)
    real(kind=8) :: p(3)
    real(kind=8) :: expected_p(3)
    logical :: test_passed

    ! Sample input
    r = (/ 1.0d0, 2.0d0, 3.0d0 /)

    ! Expected results
    expected_p = (/ 6.0d0, 14.0d0, 36.0d0 /)

    ! Call the subroutine
    call fi_a3(r, p)

    ! Check results
    test_passed = all(abs(p - expected_p) < 1.0d-6)

    if (test_passed) then
        print *, "Test passed."
    else
        print *, "Test failed."
    end if
end program test_fi_a3