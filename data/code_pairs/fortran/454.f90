module matrix_operations
    implicit none
contains
    subroutine r3mtm(a, b, c)
        real(8), intent(in) :: a(3,3), b(3,3)
        real(8), intent(out) :: c(3,3)
        integer :: i, j, k

        do i = 1, 3
            do j = 1, 3
                c(i, j) = 0.0d0
                do k = 1, 3
                    c(i, j) = c(i, j) + a(i, k) * b(k, j)
                end do
            end do
        end do
    end subroutine r3mtm
end module matrix_operations