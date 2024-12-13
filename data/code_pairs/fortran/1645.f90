! File: specific_sinh_r4.f90
elemental function specific__sinh_r4(parm) result(specific_sinh)
    real(kind=4), intent(in) :: parm
    real(kind=4) :: specific_sinh
    specific_sinh = sinh(parm)
end function specific__sinh_r4