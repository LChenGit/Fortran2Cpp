module test_module
  implicit none
contains
  function test1(n) result(res)
    integer, intent(in) :: n
    character(len=n) :: res
    res = "     "
  end function test1

  function test2() result(res)
    character(1) :: res
    res = " "
  end function test2

  function test4(n) result(res)
    integer, intent(in) :: n
    character(len=n) :: res
    res = "     "
  end function test4

  function test5() result(res)
    character(1) :: res
    res = " "
  end function test5
end module test_module

program test_fortran_functions
  use test_module
  implicit none

  print *, 'Test1: ', test1(5)
  print *, 'Test2: ', test2()
  print *, 'Test4: ', test4(5)
  print *, 'Test5: ', test5()
end program test_fortran_functions