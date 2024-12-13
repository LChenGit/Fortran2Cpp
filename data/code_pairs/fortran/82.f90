module math_functions
    implicit none
contains
    elemental function specific__asin_r4(parm) result(res)
        real(kind=4), intent(in) :: parm
        real(kind=4) :: res
        res = asin(parm)
    end function specific__asin_r4
end module math_functions