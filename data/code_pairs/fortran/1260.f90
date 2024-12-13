module m2
  implicit none
contains
  function func(a) result(funcResult)
    implicit none
    integer, intent(in) :: a
    integer :: funcResult
    funcResult = a*8
  end function func

  function ent(a) result(func2)
    implicit none
    integer, intent(in) :: a
    real :: func2
    func2 = -a*4.0
  end function ent
end module m2

module m3
  implicit none
contains
  function func(a) result(res)
    implicit none
    integer, intent(in) :: a
    integer :: res
    res = a*12
  end function func

  function ent(a) result(func2)
    implicit none
    integer, intent(in) :: a
    real :: func2
    func2 = -a*6.0
  end function ent
end module m3

program main
  use m2
  use m3
  implicit none
  integer :: a
  real :: result1, result2
  integer :: result3, result4

  a = 2

  ! Test functionality equivalent to m2
  result3 = func(a)
  print *, "func_m2(2):", result3
  result1 = ent(a)
  print *, "ent_m2(2):", result1

  ! Test functionality equivalent to m3
  result4 = m3::func(a)
  print *, "func_m3(2):", result4
  result2 = m3::ent(a)
  print *, "ent_m3(2):", result2
end program main