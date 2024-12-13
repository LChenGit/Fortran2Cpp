module specific_atan_mod
  implicit none
  contains
    elemental function specific__atan_r4 (parm)
      real (kind=4), intent (in) :: parm
      real (kind=4) :: specific__atan_r4
      specific__atan_r4 = atan (parm)
    end function specific__atan_r4
end module specific_atan_mod