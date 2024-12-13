elemental function specific__anint_r8(parm) result(res)
    use, intrinsic :: iso_fortran_env, only: real64
    real(kind=real64), intent(in) :: parm
    real(kind=real64) :: res

    res = anint(parm)
end function specific__anint_r8