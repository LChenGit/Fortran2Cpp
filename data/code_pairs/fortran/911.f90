module m11
contains
    function add_two_numbers(a, b)
        integer, intent(in) :: a, b
        integer :: add_two_numbers
        add_two_numbers = a + b
    end function add_two_numbers
end module m11

program main
    use m11
    implicit none
    integer :: result

    result = add_two_numbers(2, 3)

    print *, "Testing add_two_numbers with inputs 2 and 3."
    if (result == 5) then
        print *, "Test passed. Result is:", result
    else
        print *, "Test failed. Result is:", result
    endif
end program main