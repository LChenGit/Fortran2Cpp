module cnvg_I
    implicit none
    contains

    subroutine cnvg(PNEW, P, P1, NITER, PL)
        ! Using explicit typing for clarity
        integer, intent(in) :: NITER
        real(kind=8), dimension(1234), intent(inout) :: PNEW, P, P1
        real(kind=8), intent(out) :: PL
        integer :: i

        PL = 0.0
        do i = 1, NITER
            PNEW(i) = (P(i) + P1(i)) / 2.0
            PL = PL + PNEW(i)
        end do
    end subroutine cnvg
end module cnvg_I