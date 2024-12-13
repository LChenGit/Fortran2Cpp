! Fortran program with subroutines
module test_module
    implicit none

contains

    subroutine sub1(x)
        integer, intent(in) :: x
        print *, 'sub1:', x
    end subroutine sub1

    subroutine sub1_c(x) bind(c)
        integer, intent(in) :: x
        print *, 'sub1_c:', x
    end subroutine sub1_c

    subroutine sub2_c(x) bind(c)
        integer, intent(in) :: x
        print *, 'sub2_c:', x
    end subroutine sub2_c

    subroutine sub2(x)
        integer, intent(in) :: x
        print *, 'sub2:', x
    end subroutine sub2

    subroutine sub3_c(x) bind(c)
        integer, intent(in) :: x
        print *, 'sub3_c:', x
    end subroutine sub3_c

    subroutine sub3_c_c(x) bind(c)
        integer, intent(in) :: x
        print *, 'sub3_c_c:', x
    end subroutine sub3_c_c

end module test_module

program test_fortran_subroutines
    use test_module
    implicit none
    integer :: test_val

    test_val = 123
    call sub1(test_val)
    call sub1_c(test_val)
    call sub2_c(test_val)
    call sub2(test_val)
    call sub3_c(test_val)
    call sub3_c_c(test_val)
end program test_fortran_subroutines