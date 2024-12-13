module div_by_five_module
contains
    subroutine print_div_by_five(n)
        implicit none
        integer, intent(in) :: n
        integer :: i
        do i = 1, n
            if (mod(i, 5) == 0) then
                print *, i
            end if
        end do
    end subroutine print_div_by_five
end module div_by_five_module