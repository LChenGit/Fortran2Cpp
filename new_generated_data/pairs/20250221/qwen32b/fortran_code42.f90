module kinds
    implicit none
    integer, parameter :: DP = kind(1.0d0)
end module kinds

program test_entropy
    use kinds
    implicit none

    ! Variable declarations
    real(DP) :: f1(1), f2(3), f3(1)
    integer :: nx1, nx2, nx3
    real(DP) :: temp1, temp2, temp3
    real(DP) :: ent1, ent2, ent3
    real(DP) :: expected2

    ! Test Case 1: Single element array
    f1 = 1.0
    nx1 = 1
    temp1 = 1.0
    call entropy(f1, temp1, nx1, ent1)
    if (abs(ent1 - (-2.0 * temp1 * (0.5 * log(0.5 + 1.0e-10) + 0.5 * log(0.5 + 1.0e-10)))) > 1.0e-6) then
        write(*,*) "Test Case 1 Failed: assertion failed"
        call exit(1)
    endif
    write(*,*) "Test Case 1 Passed!"

    ! Test Case 2: Multiple elements
    f2 = [0.5, 1.0, 0.0]
    nx2 = 3
    temp2 = 2.0
    call entropy(f2, temp2, nx2, ent2)
    ! Corrected expected value calculation
    expected2 = -2.0 * temp2 * (0.25 * log(0.25 + 1.0e-10) + 0.75 * log(0.75 + 1.0e-10) &
                                 + 0.5 * log(0.5 + 1.0e-10) + 0.5 * log(0.5 + 1.0e-10) &
                                 + 0.0 * log(0.0 + 1.0e-10) + 1.0 * log(1.0 + 1.0e-10))
    if (abs(ent2 - expected2) > 1.0e-6) then
        write(*,*) "Test Case 2 Failed: assertion failed"
        call exit(1)
    endif
    write(*,*) "Test Case 2 Passed!"

    ! Test Case 3: Edge case with zero
    f3 = 0.0
    nx3 = 1
    temp3 = 1.0
    call entropy(f3, temp3, nx3, ent3)
    if (abs(ent3 - (-2.0 * temp3 * (0.0 * log(0.0 + 1.0e-10) + 1.0 * log(1.0 + 1.0e-10)))) > 1.0e-6) then
        write(*,*) "Test Case 3 Failed: assertion failed"
        call exit(1)
    endif
    write(*,*) "Test Case 3 Passed!"

    write(*,*) "All Tests Passed!"
end program test_entropy

subroutine entropy(f, temp, nx, ent)
    use kinds
    implicit none

    real(DP), intent(in) :: f(nx)
    real(DP), intent(in) :: temp
    integer, intent(in) :: nx
    real(DP), intent(out) :: ent

    real(DP), parameter :: eps = 1.0e-10
    real(DP) :: fm
    integer :: i

    ent = 0.0
    do i = 1, nx
        fm = 0.5 * f(i)
        ent = ent + fm * log(eps + fm) + (1.0 - fm) * log(eps + 1.0 - fm)
    end do
    ent = -2.0 * temp * ent
end subroutine entropy