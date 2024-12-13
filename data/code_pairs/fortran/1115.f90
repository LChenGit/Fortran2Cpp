module math_operations
    implicit none
contains
    function add(a, b) result(c)
        integer, intent(in) :: a, b
        integer :: c

        c = a + b
    end function add
end module math_operations

program test_addition
    use math_operations
    implicit none

    integer :: result

    result = add(1, 2)
    print *, 'Adding 1 and 2 gives: ', result
end program test_addition