program test_square_function
    implicit none
    real :: x, result

    x = 2.0
    result = square(x)
    print *, "Fortran Stdout: The square of", x, "is", result

contains

    function square(x) result(res)
        real, intent(in) :: x
        real :: res
        res = x * x
    end function square

end program test_square_function