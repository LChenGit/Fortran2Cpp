module square_mod
    implicit none
contains

    function square(x) result(y)
        real, intent(in) :: x
        real :: y

        y = x**2
    end function square

end module square_mod