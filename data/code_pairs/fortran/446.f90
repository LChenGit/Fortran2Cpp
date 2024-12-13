module dpowint_mod
  implicit none
contains
  double precision function dpowint(xlow, xhigh, ylow, yhigh, xval, pow)
    implicit none
    double precision, intent(in) :: xlow, xhigh, ylow, yhigh, xval, pow
    double precision :: EPSLON
    EPSLON = 1.0D-20

    if (abs(xhigh-xlow) < EPSLON) then
      dpowint = (yhigh + ylow) / 2.0D0
    else
      dpowint = ylow + (yhigh - ylow) * &
                ((xval - xlow) / (xhigh - xlow))**pow
    endif
  end function dpowint
end module dpowint_mod