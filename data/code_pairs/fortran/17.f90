program trivialTest
  implicit none
contains

  subroutine sayHello()
    print *, "Hello, World!"
  end subroutine sayHello

  function square(x) result(res)
    implicit none
    integer, intent(in) :: x
    integer :: res
    res = x * x
  end function square

end program trivialTest

! Main routine
call sayHello()
print *, "The square of 5 is ", square(5)