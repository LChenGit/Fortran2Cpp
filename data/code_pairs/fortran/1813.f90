module funcs
    implicit none
contains
    function assumed_len(x) result(res)
        character(len=:), allocatable :: res
        integer, intent(in) :: x
        res = repeat(' ', x)  ! Creates a string with x spaces.
    end function assumed_len
end module funcs