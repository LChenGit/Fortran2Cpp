module mod12
    implicit none
contains
    function square(x) result(res)
        integer, intent(in) :: x
        integer :: res
        res = x**2
    end function square
end module mod12