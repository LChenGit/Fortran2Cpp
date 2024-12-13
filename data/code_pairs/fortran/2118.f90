module m1
contains
  subroutine s1(f)
    interface
      function f()
        integer f
      end function f
    end interface
    ! This subroutine is meant to demonstrate an interface usage.
  end subroutine s1

  subroutine s2(x)
    integer :: x
    ! This subroutine demonstrates passing an integer.
  end subroutine s2
end module m1

program test_program
  use m1
  implicit none

contains
  integer function w()
    w = 1
  end function w

  integer function x()
    x = 1
  end function x

  integer function y()
    y = 1
  end function y

  integer function z()
    z = 1
  end function z

  subroutine run_tests()
    print *, 'Testing s1 with function y'
    call s1(y)
    print *, 'Testing s1 with function z'
    call s1(z)
    print *, 'Testing s1 with function w'
    call s1(w)
    print *, 'Testing s1 with function x'
    call s1(x)
    print *, 'Testing s2 with x()'
    call s2(x())
    print *, 'All tests passed.'
  end subroutine run_tests

end program test_program