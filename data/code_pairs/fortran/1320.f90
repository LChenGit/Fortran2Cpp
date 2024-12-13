module specific_functions
    implicit none
contains
    elemental function specific__dim_i8(p1, p2) result(out)
        integer(kind=8), intent(in) :: p1, p2
        integer(kind=8) :: out
        out = dim(p1, p2)
    end function specific__dim_i8
end module specific_functions