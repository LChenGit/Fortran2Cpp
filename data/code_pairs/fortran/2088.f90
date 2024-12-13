module mod
    implicit none

    type :: t
    end type t

contains

    subroutine s1(x)
        type(t), intent(in) :: x
        print *, "s1 called"
    end subroutine s1

    subroutine s2(x)
        class(*), intent(in) :: x
        print *, "s2 called with integer"
    end subroutine s2

end module mod