module dawrit_I
    implicit none
contains
    subroutine dawrit(V, LEN, NREC)
        integer, intent(in) :: LEN, NREC
        real(8), dimension(LEN), intent(in) :: V
        real(8) :: sum
        integer :: i

        sum = 0.0
        do i = 1, LEN
            sum = sum + V(i)
        end do
        print *, 'Sum = ', sum
    end subroutine dawrit
end module dawrit_I