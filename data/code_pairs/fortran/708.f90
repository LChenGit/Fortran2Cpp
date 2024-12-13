module foo_mod
contains
    integer function foo(a, b, n) result(r)
        integer, intent(in) :: a(n), n
        integer, intent(out) :: b(n)
        integer :: i
        r = 0
        b(1) = a(1)
        r = r + a(1)
        do i = 2, n
            b(i) = b(i-1) + a(i)
            r = r + a(i)
        end do
    end function foo
end module foo_mod

program test_foo
    use foo_mod
    implicit none
    integer, parameter :: n = 5
    integer :: a(n) = [1, 2, 3, 4, 5]
    integer :: b(n)
    integer :: sum, i

    sum = foo(a, b, n)

    print *, 'Sum:', sum
    print *, 'b:', (b(i), i = 1, n)
end program test_foo