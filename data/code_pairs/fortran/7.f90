! Fortran Code - Module and Program with Unit Test
module m1
  integer :: i = 0
contains
  subroutine set_i(val)
    integer, intent(in) :: val
    i = val
  end subroutine set_i

  function get_i() result(res)
    integer :: res
    res = i
  end function get_i
end module m1

program main
  use m1
  integer :: test_i

  call set_i(5)
  test_i = get_i()

  if (test_i == 5) then
    print *, "Test Passed: i is 5"
  else
    print *, "Test Failed: i is not 5"
  end if
end program main