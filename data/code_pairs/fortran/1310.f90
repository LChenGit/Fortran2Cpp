elemental function specific__sin_r4(parm) result(sine_val)
    use, intrinsic :: iso_fortran_env, only: real32
    real(real32), intent(in) :: parm
    real(real32) :: sine_val

    sine_val = sin(parm)
end function specific__sin_r4