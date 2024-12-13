module sum_module
    implicit none
contains
    function sumSelectedIntegers(array, size, mask) result(sum)
        integer(kind=2), intent(in) :: array(*)
        integer(kind=4), intent(in) :: size
        logical, intent(in) :: mask(*)
        integer(kind=2) :: sum
        integer :: i

        sum = 0
        do i = 1, size
            if (mask(i)) then
                sum = sum + array(i)
            end if
        end do
    end function sumSelectedIntegers
end module sum_module