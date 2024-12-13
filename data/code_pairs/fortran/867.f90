! square.f90
module square_module
    implicit none
contains
    function square(x) result(square_result)
        real, intent(in) :: x
        real :: square_result

        square_result = x * x
    end function square
end module square_module

program test_square
    use square_module
    implicit none
    real :: number, result

    number = 4.0
    result = square(number)
    print *, 'Square of', number, 'is', result
end program test_square