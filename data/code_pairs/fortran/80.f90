module my_functions
  implicit none
contains
  function foo(i) result(s)
    integer, intent(in) :: i
    character(len=4) :: s
    if (i < 0) then
       s = "1234"
    else
       s = "abcd"
    end if
  end function foo

  function bar(i) result(s)
    integer, intent(in) :: i
    character(len=4) :: s
    if (i < 0) then
      s = "4567"
    else
      s = foo(i)
    end if
  end function bar
end module my_functions