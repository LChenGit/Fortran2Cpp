module notwin_mod
  implicit none
contains
  logical function notwin(xw1,xw2,x) 
    double precision, intent(in) :: xw1, xw2, x
    if (xw1 > xw2) then
      notwin = .false.
    else
      notwin = x < xw1 .or. x > xw2
    end if
  end function notwin
end module notwin_mod