module test_mod
contains
    subroutine test(n, a, b, c)
        integer, intent(in) :: n
        real, intent(inout) :: a(:)
        real, intent(in) :: b(:), c(:)
        integer :: i
        do concurrent (i = 1:n)
            a(i) = b(i) + c(i)
        end do
    end subroutine test
end module test_mod

program test_program
    use test_mod
    implicit none
    integer, parameter :: n = 5
    real :: a(n), b(n), c(n)

    ! Test 1: Positive numbers
    b = [1.0, 2.0, 3.0, 4.0, 5.0]
    c = [5.0, 4.0, 3.0, 2.0, 1.0]
    call test(n, a, b, c)
    print *, 'Test 1: Positive numbers'
    print *, 'Expected: 6.0, 6.0, 6.0, 6.0, 6.0'
    print *, 'Result: ', a

    ! Test 2: Negative numbers
    b = [-1.0, -2.0, -3.0, -4.0, -5.0]
    c = [-5.0, -4.0, -3.0, -2.0, -1.0]
    call test(n, a, b, c)
    print *, 'Test 2: Negative numbers'
    print *, 'Expected: -6.0, -6.0, -6.0, -6.0, -6.0'
    print *, 'Result: ', a

    ! Test 3: Zeros and positive numbers
    b = [0.0, 0.0, 0.0, 0.0, 0.0]
    c = [1.0, 2.0, 3.0, 4.0, 5.0]
    call test(n, a, b, c)
    print *, 'Test 3: Zeros and positive numbers'
    print *, 'Expected: 1.0, 2.0, 3.0, 4.0, 5.0'
    print *, 'Result: ', a
end program test_program