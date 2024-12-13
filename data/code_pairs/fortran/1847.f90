module sum0_module
    implicit none
contains
    function sum0_i(arr, mask) result(resultSum)
        integer, intent(in) :: arr(:)
        logical, intent(in) :: mask(:)
        integer :: resultSum
        integer :: i

        resultSum = 0
        do i = 1, size(arr)
            if (mask(i)) then
                resultSum = resultSum + arr(i)
            endif
        end do
    end function sum0_i
end module sum0_module