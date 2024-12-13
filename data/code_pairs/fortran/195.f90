module specific_functions
  implicit none
contains
  elemental function specific__aint_r4(parm) result(res)
    real(kind=4), intent(in) :: parm
    real(kind=4) :: res

    res = aint(parm)
  end function specific__aint_r4
end module specific_functions