module myModule
contains
    function compute(x) result(y)
        integer, intent(in) :: x
        integer :: y
        y = x * x
    end function compute
end module myModule