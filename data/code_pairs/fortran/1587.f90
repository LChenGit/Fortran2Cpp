module orders
implicit none
contains
    function double_order(x) result(y)
        double precision, intent(in) :: x
        double precision :: y
        y = 2*x
    end function double_order

    function integer_order(x) result(y)
        integer, intent(in) :: x
        integer :: y
        y = 2*x
    end function integer_order

    function real_order(x) result(y)
        real, intent(in) :: x
        real :: y
        y = 2*x
    end function real_order
end module orders