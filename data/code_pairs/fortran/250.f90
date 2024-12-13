module square_module
    implicit none
contains
    function square(x) result(squareResult)
        integer, intent(in) :: x
        integer :: squareResult

        squareResult = x * x
    end function square
end module square_module

program testSquare
    use square_module
    implicit none

    ! Test cases for the square function
    call assertEqual(square(5), 25)
    call assertEqual(square(-4), 16)
    call assertEqual(square(0), 0)

    print *, "All Fortran tests passed."

contains

    subroutine assertEqual(a, b)
        integer, intent(in) :: a, b

        if (a /= b) then
            print *, "Test failed: ", a, " not equal to ", b
            stop
        end if
    end subroutine assertEqual

end program testSquare