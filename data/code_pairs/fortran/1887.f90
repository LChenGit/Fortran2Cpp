program testFoo
  implicit none

contains

  integer function foo()
    integer, save :: i = 0
    i = i + 1
    foo = i
  end function foo

end program testFoo