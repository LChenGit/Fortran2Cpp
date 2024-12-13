module math_operations
    implicit none
contains
    elemental function specific__sqrt_c8(parm)
        complex(kind=8), intent(in) :: parm
        complex(kind=8) :: specific__sqrt_c8
        specific__sqrt_c8 = sqrt(parm)
    end function specific__sqrt_c8
end module math_operations