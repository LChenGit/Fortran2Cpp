module segment
  implicit none
contains
  elemental function whichSegment(x, xLower, xUpper, iLower, iUpper) result(i)
    double precision, intent(in) :: x, xLower, xUpper
    integer, intent(in) :: iLower, iUpper
    integer :: i
    i = iLower + floor(0.5D0 + (x - xLower) / (xUpper - xLower) * (iUpper - iLower))
  end function whichSegment
end module segment