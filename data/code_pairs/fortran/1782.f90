module tanh_module
  implicit none
contains
  elemental function specific__tanh_r8(parm) result(res)
    real(kind=8), intent(in) :: parm
    real(kind=8) :: res

    res = tanh(parm)
  end function specific__tanh_r8
end module tanh_module