module c_funloc_tests_5
  use, intrinsic :: iso_c_binding, only: c_funloc, c_funptr

contains

  subroutine sub0() bind(c)
    type(c_funptr) :: my_c_funptr

    my_c_funptr = c_funloc(sub1) 
    call sub1()

    my_c_funptr = c_funloc(func0)
    print *, "Result of func0: ", func0(42)
  end subroutine sub0

  subroutine sub1() 
    print *, "sub1 called"
  end subroutine sub1

  function func0(desired_retval) result(res)
    use, intrinsic :: iso_c_binding, only: c_int
    integer(c_int), value :: desired_retval
    integer(c_int) :: res
    res = desired_retval
  end function func0
end module c_funloc_tests_5