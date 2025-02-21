program main
    implicit none

    ! Variable declarations
    integer, parameter :: npix = 4, nlines = 4, inval = -999, idx = 2, idy = 2
    integer, parameter :: nbin_expected = 4
    integer :: ia(npix * nlines)
    integer :: nbin

    ! Expected results
    real :: x_expected(nbin_expected)
    real :: y_expected(nbin_expected)
    real :: z_expected(nbin_expected)
    real :: w_expected(nbin_expected)

    ! Fortran arrays
    real :: x_fortran(nbin_expected)
    real :: y_fortran(nbin_expected)
    real :: z_fortran(nbin_expected)
    real :: w_fortran(nbin_expected)

    ! Initialize input array
    call initialize_array(ia, npix, nlines)

    ! Assign expected results
    x_expected = (/1.5, 3.5, 1.5, 3.5/)
    y_expected = (/1.5, 1.5, 3.5, 3.5/)
    z_expected = (/3.5, 5.5, 11.5, 13.5/)
    w_expected = (/2.0, 2.0, 2.0, 2.0/)

    ! Run Fortran code
    call binint(ia, npix, nlines, inval, idx, idy, x_fortran, y_fortran, z_fortran, w_fortran, nbin)

    ! Compare results
    if (nbin /= nbin_expected) then
        print *, "Number of bins mismatch."
        stop
    endif

    if (.not. has_close_elements(x_fortran, x_expected, 1e-6)) then
        print *, "x values do not match."
        stop
    endif

    if (.not. has_close_elements(y_fortran, y_expected, 1e-6)) then
        print *, "y values do not match."
        stop
    endif

    if (.not. has_close_elements(z_fortran, z_expected, 1e-6)) then
        print *, "z values do not match."
        stop
    endif

    if (.not. has_close_elements(w_fortran, w_expected, 1e-6)) then
        print *, "w values do not match."
        stop
    endif

    print *, "All tests passed!"
    stop

contains

subroutine binint(ia, npix, nlines, inval, idx, idy, x, y, z, w, nbin)
    implicit none
    integer, intent(in) :: ia(npix * nlines), npix, nlines, inval, idx, idy
    real, intent(out) :: x(:), y(:), z(:), w(:)
    integer, intent(out) :: nbin
    integer :: jmin, jmax, imin, imax, j, i, index, sum, npt, ix, iy

    nbin = 0
    do jmin = 0, nlines - 1, idy
        jmax = min(jmin + idy, nlines)
        do imin = 0, npix - 1, idx
            imax = min(imin + idx, npix)
            sum = 0
            npt = 0
            ix = 0
            iy = 0
            do j = jmin, jmax - 1
                do i = imin, imax - 1
                    index = j * npix + i + 1  ! Corrected index calculation
                    if (ia(index) /= inval) then
                        sum = sum + ia(index)
                        npt = npt + 1
                        ix = ix + (i + 1)  ! Adjusting for 1-based indexing
                        iy = iy + (j + 1)
                    endif
                enddo
            enddo
            if (npt >= 1) then
                nbin = nbin + 1
                if (nbin > size(x)) then
                    print *, "Output arrays need resizing."
                    stop
                endif
                x(nbin) = real(ix) / real(npt)
                y(nbin) = real(iy) / real(npt)
                z(nbin) = real(sum) / real(npt)
                w(nbin) = sqrt(real(npt))
            endif
        enddo
    enddo
end subroutine binint

subroutine initialize_array(ia, npix, nlines)
    implicit none
    integer, intent(out) :: ia(npix * nlines)
    integer, intent(in) :: npix, nlines
    integer :: j, i

    do j = 0, nlines - 1
        do i = 0, npix - 1
            ia(j * npix + i + 1) = j * npix + i + 1  ! Corrected index calculation
        enddo
    enddo
end subroutine initialize_array

logical function has_close_elements(a, b, tolerance)
    implicit none
    real, intent(in) :: a(:), b(:)
    real, intent(in) :: tolerance
    integer :: i

    if (size(a) /= size(b)) then
        has_close_elements = .false.
        return
    endif

    do i = 1, size(a)
        if (abs(a(i) - b(i)) > tolerance) then
            has_close_elements = .false.
            return
        endif
    enddo

    has_close_elements = .true.
end function has_close_elements

end program main