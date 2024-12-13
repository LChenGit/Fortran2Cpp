module specific_functions_mod
  implicit none
contains
  ! Definition of the specific__log10_r4 function
  elemental function specific__log10_r4 (parm) result(log10_result)
    real(kind=4), intent(in) :: parm
    real(kind=4) :: log10_result
  
    log10_result = log10(parm)
  end function specific__log10_r4
end module specific_functions_mod