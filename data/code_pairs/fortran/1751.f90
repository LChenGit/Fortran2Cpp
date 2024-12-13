module spcore_I
    implicit none
contains

    subroutine spcore(NI, NJ, R, CORE)
        integer, intent(in) :: NI, NJ
        real(kind=8), intent(in) :: R
        real(kind=8), dimension(10,2), intent(out) :: CORE
        integer :: i

        do i = 1, 10
            CORE(i, 1) = NI * R + i
            CORE(i, 2) = NJ * R - i
        end do
    end subroutine spcore
end module spcore_I