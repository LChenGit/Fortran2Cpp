module mathlib
  implicit none
  
  private
  public :: add, sub, mul, div, md

contains
  pure function add(lhs, rhs) result(res)
    integer, intent(in) :: lhs, rhs
    integer :: res
    res = lhs + rhs
  end function add

  pure function sub(lhs, rhs) result(res)
    integer, intent(in) :: lhs, rhs
    integer :: res
    res = lhs - rhs
  end function sub

  pure function mul(lhs, rhs) result(res)
    integer, intent(in) :: lhs, rhs
    integer :: res
    res = lhs * rhs
  end function mul

  pure function div(lhs, rhs) result(res)
    integer, intent(in) :: lhs, rhs
    integer :: res
    res = lhs / rhs
  end function div

  pure function md(lhs, rhs) result(res)
    integer, intent(in) :: lhs, rhs
    integer :: res
    res = mod(lhs, rhs)
  end function md
end module mathlib