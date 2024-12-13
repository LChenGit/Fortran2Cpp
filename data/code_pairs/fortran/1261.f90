subroutine intern(j, c, mb, nb, r, dr, nbond)
    integer, intent(in) :: j, nbond
    double precision, dimension(j,4,3), intent(in) :: c
    integer, dimension(nbond), intent(in) :: mb, nb
    double precision, dimension(j,nbond), intent(out) :: r
    double precision, dimension(j,nbond,4,3), intent(out) :: dr
    integer :: i
    double precision :: dx, dy, dz

    do i = 1, nbond
        dx = c(j, mb(i), 1) - c(j, nb(i), 1)
        dy = c(j, mb(i), 2) - c(j, nb(i), 2)
        dz = c(j, mb(i), 3) - c(j, nb(i), 3)
        r(j, i) = sqrt(dx**2 + dy**2 + dz**2)
        dr(j, i, mb(i), 1) = dx / r(j, i)
        dr(j, i, mb(i), 2) = dy / r(j, i)
        dr(j, i, mb(i), 3) = dz / r(j, i)
        dr(j, i, nb(i), 1) = -dx / r(j, i)
        dr(j, i, nb(i), 2) = -dy / r(j, i)
        dr(j, i, nb(i), 3) = -dz / r(j, i)
    end do
end subroutine intern

program test_intern
    implicit none
    integer, parameter :: n=1, nbond=2
    double precision, dimension(n,nbond) :: r
    double precision, dimension(n,nbond,4,3) :: dr
    double precision, dimension(n,4,3) :: c
    integer, dimension(nbond) :: mb, nb

    ! Initialize mb and nb
    mb = (/1, 2/)
    nb = (/3, 4/)

    ! Initialize matrix c
    c(1, 1, 1) = 0.0; c(1, 2, 1) = 1.0; c(1, 3, 1) = 1.0; c(1, 4, 1) = 0.0
    c(1, 3, 2) = 1.0; c(1, 4, 2) = 1.0; c(1, :, 3) = 0.0

    call intern(1, c, mb, nb, r, dr, nbond)

    ! Output results for manual inspection
    print *, 'Fortran results:'
    print *, 'r:', r
    print *, 'dr(mb):', dr(:,:,1,:)
    print *, 'dr(nb):', dr(:,:,2,:)
end program test_intern