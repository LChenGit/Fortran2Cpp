! descramble_matrix.f90
subroutine descramble_matrix(mat, na, nfps, ixshells, nshells)
    implicit none
    integer, intent(in) :: na, nshells
    integer, intent(in) :: nfps(nshells), ixshells(nshells)
    double precision, intent(inout) :: mat(na, na)
    double precision :: xa(na)
    integer :: ixa(na)
    integer :: nfps_orig(nshells)
    integer :: i, j, istart, ishell, n

    if (na .gt. 0) then
        do i = 1, nshells
            nfps_orig(ixshells(i)) = nfps(i)
        end do

        istart = 1
        do i = 1, nshells
            ishell = ixshells(i)

            n = 0
            do j = 1, ishell-1
                n = n + nfps_orig(j)
            end do

            do j = 1, nfps_orig(ishell)
                ixa(istart) = n + j
                istart = istart + 1
            end do
        end do

        do j = 1, na
            do i = 1, na
                xa(i) = mat(i, j)
            end do

            do i = 1, na
                mat(ixa(i), j) = xa(i)
            end do
        end do

        do i = 1, na
            do j = 1, na
                xa(j) = mat(i, j)
            end do

            do j = 1, na
                mat(i, ixa(j)) = xa(j)
            end do
        end do
    endif
end subroutine descramble_matrix