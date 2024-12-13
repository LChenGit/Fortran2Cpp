module utilities_module
    implicit none
contains
    function square(input) result(output)
        real, intent(in) :: input
        real :: output
        output = input * input
    end function square
end module utilities_module