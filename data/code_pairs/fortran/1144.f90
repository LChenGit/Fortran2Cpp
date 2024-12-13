module modE
  implicit none
contains
  function square(x) result(res)
    real, intent(in) :: x
    real :: res
    res = x**2
  end function square
end module modE

program testSquare
  use modE
  implicit none
  real :: inputValue = 3.0
  real :: result

  result = square(inputValue)

  print *, "The square of ", inputValue, " is ", result
end program testSquare