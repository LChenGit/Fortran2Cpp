module GLQGridCoordModule
    use SHTOOLS, only: NGLQSH, PreGLQ
    implicit none
contains
    subroutine GLQGridCoord(latglq, longlq, lmax, nlat, nlong)
        implicit none
        integer, intent(in) :: lmax
        integer, intent(out) :: nlat, nlong
        real(8), intent(out) :: latglq(:), longlq(:)
        real(8) :: pi, zero(lmax+1), w(lmax+1)
        integer :: i

        pi = acos(-1.0d0)
        nlat = NGLQSH(lmax)
        nlong = 2*lmax + 1

        call PreGLQ(-1.0d0, 1.0d0, nlat, zero, w)

        do i = 1, nlat
            latglq(i) = asin(zero(i)) * 180.0d0 / pi
        end do

        do i = 1, nlong
            longlq(i) = 360.0d0 * (i-1) / nlong
        end do
    end subroutine GLQGridCoord
end module GLQGridCoordModule

program test
    use GLQGridCoordModule
    implicit none
    real(8), allocatable :: latglq(:), longlq(:)
    integer :: lmax, nlat, nlong

    lmax = 3
    allocate(latglq(lmax+1), longlq(2*lmax+1))

    call GLQGridCoord(latglq, longlq, lmax, nlat, nlong)

    print *, "Latitude: ", latglq
    print *, "Longitude: ", longlq
end program test