module specific_abs_module
    implicit none
    contains

    elemental function specific__abs_c8(parm) result(res)
        complex(kind=8), intent(in) :: parm
        real(kind=8) :: res

        res = abs(parm)
    end function specific__abs_c8
end module specific_abs_module