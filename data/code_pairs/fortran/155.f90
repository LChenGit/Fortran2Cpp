module NoBindMod
  use, intrinsic :: iso_c_binding, only: c_double
  implicit none

contains

  function Func1() result(res)
    real(kind=c_double) :: res
    res = 0.0d0
  end function Func1

  function Func2() result(res)
    real(kind=c_double) :: res
    res = 0.0d0
  end function Func2

  function Func3() result(res)
    real(kind=c_double) :: res
    res = 0.0d0
  end function Func3

end module NoBindMod

! Test program for the NoBindMod module
program test
  use NoBindMod
  implicit none

  real(kind=c_double) :: result

  ! Test Func1
  result = Func1()
  if (result /= 0.0d0) then
    print *, "Func1 FAILED."
  else
    print *, "Func1 PASSED."
  endif

  ! Test Func2
  result = Func2()
  if (result /= 0.0d0) then
    print *, "Func2 FAILED."
  else
    print *, "Func2 PASSED."
  endif

  ! Test Func3
  result = Func3()
  if (result /= 0.0d0) then
    print *, "Func3 FAILED."
  else
    print *, "Func3 PASSED."
  endif

end program test