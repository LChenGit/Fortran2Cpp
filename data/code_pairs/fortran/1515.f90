module math_operations
    implicit none
contains
    ! Calculates the square of a number
    function square(x)
        integer, intent(in) :: x
        integer :: square
        
        square = x * x
    end function square
end module math_operations