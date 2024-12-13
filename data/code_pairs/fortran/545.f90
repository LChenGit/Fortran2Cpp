function square(x) result(res)
    implicit none
    real, intent(in) :: x
    real :: res
    res = x * x
end function square