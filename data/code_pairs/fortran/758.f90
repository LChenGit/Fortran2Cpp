module tanh_module
implicit none
contains

elemental function specific__tanh_r4 (parm) result(res)
    real (kind=4), intent (in) :: parm
    real (kind=4) :: res

    res = tanh (parm)
end function specific__tanh_r4
end module tanh_module