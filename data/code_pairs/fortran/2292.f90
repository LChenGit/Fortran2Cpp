module abs_module
contains
    elemental function specific_abs_r4(parm) result(res)
        real(kind=4), intent(in) :: parm
        real(kind=4) :: res
        res = abs(parm)
    end function specific_abs_r4
end module abs_module