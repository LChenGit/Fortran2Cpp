! Enums.f90 - The module
module Enums
  implicit none
  real :: somevar = 0.0
  real, parameter :: othervar = 42.0

  enum, bind(c)
     enumerator :: red = 1, blue, gold, silver, bronze, purple
  end enum

contains

  function Func(arg) result(res)
    real, intent(in) :: arg
    real :: res
    res = arg
  end function Func

end module Enums

! TestEnums.f90 - The test program
program TestEnums
  use Enums
  implicit none

  somevar = 3.14
  if (somevar == 3.14) then
    print *, "Test passed: somevar"
  else
    print *, "Test failed: somevar"
  end if

  if (othervar == 42.0) then
    print *, "Test passed: othervar"
  else
    print *, "Test failed: othervar"
  end if

  if (Func(2.71) == 2.71) then
    print *, "Test passed: Func"
  else
    print *, "Test failed: Func"
  end if
end program TestEnums