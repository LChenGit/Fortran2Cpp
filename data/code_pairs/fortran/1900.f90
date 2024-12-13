! This module defines a function to add two numbers
module AdditionModule
    implicit none
contains
    ! This function adds two integers
    function add(a, b) result(sum)
        integer, intent(in) :: a
        integer, intent(in) :: b
        integer :: sum
        
        sum = a + b
    end function add
end module AdditionModule

! This program tests the add function
program TestAddition
    use AdditionModule
    implicit none
    integer :: result

    result = add(2, 3)
    print *, 'The sum of 2 and 3 is ', result
end program TestAddition