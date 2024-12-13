module symh_mod
    use, intrinsic :: iso_fortran_env, only: real64
    implicit none
contains
    subroutine symh(H, DIP, I, N, IPO)
        real(real64), dimension(*), intent(inout) :: H
        real(real64), dimension(3, *), intent(inout) :: DIP
        integer, dimension(:,:), intent(in) :: IPO
        integer, intent(in) :: I, N

        integer :: j, k
        do j = 1, N
            H(j) = H(j) + 1.0_real64
            do k = 1, 3
                H(j) = H(j) + DIP(k, j)
            end do
        end do
    end subroutine symh
end module symh_mod