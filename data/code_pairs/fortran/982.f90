module specific_anint_r4_mod
    implicit none
contains
    elemental function specific__anint_r4(parm) result(res)
        real(kind=4), intent(in) :: parm
        real(kind=4) :: res

        res = anint(parm)
    end function specific__anint_r4
end module specific_anint_r4_mod