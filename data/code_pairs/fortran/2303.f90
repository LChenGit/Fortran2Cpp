module specific_abs_c4_mod
    implicit none
    contains
    elemental function specific__abs_c4(parm) result(res)
        complex(kind=4), intent(in) :: parm
        real(kind=4) :: res

        res = abs(parm)
    end function specific__abs_c4
end module specific_abs_c4_mod