subroutine SetBoundWake(x, y, z, xBE, yBE, zBE, nb, nbe, nt)
    implicit none
    integer, intent(in) :: nb, nbe, nt
    real, dimension(:,:), intent(inout) :: x, y, z
    real, dimension(:), intent(in) :: xBE, yBE, zBE
    integer :: i, j, nei, nej

    do i = 1, nb
        nei = 1 + (i - 1) * (nbe + 1)
        do j = 0, nbe
            nej = nei + j
            x(nt, nej) = xBE(nej)
            y(nt, nej) = yBE(nej)
            z(nt, nej) = zBE(nej)
        end do
    end do
end subroutine SetBoundWake