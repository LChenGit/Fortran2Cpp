module m
  implicit none
contains
  subroutine sub(a)
    interface
      function a(x)
        real :: a
        real, intent(in) :: x
      end function a
    end interface
    print *, a(4.0)
  end subroutine sub
end module m

real function foo(x)
  real, intent(in) :: x
  foo = x * 2.0
end function foo

program testProgram
  use m
  implicit none

  call sub(foo)
  call testFoo()

contains

  subroutine testFoo()
    real :: expected, result

    expected = 8.0
    result = foo(4.0)

    if (result == expected) then
      print *, "Test passed."
    else
      print *, "Test failed."
    endif
  end subroutine testFoo

end program testProgram