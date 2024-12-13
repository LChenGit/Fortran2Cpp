! test_implementation.f90
module test_implementation
    integer, protected :: i = 0  ! Initialize 'i' with 0
public :: set_i, get_i

contains
    subroutine set_i(value)
        integer, intent(in) :: value
        i = value
    end subroutine set_i

    function get_i() result(res)
        integer :: res
        res = i
    end function get_i
end module test_implementation

program test_program
    use test_implementation
    implicit none

    call set_i(10)
    print *, "The value of 'i' is: ", get_i()
end program test_program